package DBMS.src.main.java.DBMS;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.Statement;

/**
 * Library Book Management System
 * A Java Swing application for managing library books with MySQL database connectivity.
 */
public class BookManagement implements ActionListener {

    // GUI Components
    private JFrame mainFrame;
    private JLabel lblBookId, lblTitle, lblAuthor, lblPrice;
    private JTextField txtBookId, txtTitle, txtAuthor, txtPrice;
    private JButton btnFirst, btnPrev, btnNext, btnLast, btnNew, btnAdd, btnUpdate, btnDelete;
    private Font defaultFont;

    // Database Components
    private Connection connection;
    private Statement statement;
    private ResultSet resultSet;

    /**
     * Constructor - Initializes the GUI and connects to database
     */
    public BookManagement() {
        initializeGUI();
        connectToDatabase();
    }

    /**
     * Initialize all GUI components
     */
    private void initializeGUI() {
        defaultFont = new Font("Consolas", Font.BOLD, 16);
        mainFrame = new JFrame("Library Book Management System");
        mainFrame.setBounds(50, 50, 600, 400);
        mainFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        // Initialize labels
        lblBookId = createLabel("Book ID:", 20, 20);
        lblTitle = createLabel("Title:", 20, 60);
        lblAuthor = createLabel("Author:", 20, 100);
        lblPrice = createLabel("Price:", 20, 140);

        // Initialize text fields
        txtBookId = createTextField(150, 20, 120);
        txtTitle = createTextField(150, 60, 200);
        txtAuthor = createTextField(150, 100, 200);
        txtPrice = createTextField(150, 140, 120);

        // Initialize navigation buttons
        btnFirst = createButton("First", 20, 200, 80, 35);
        btnPrev = createButton("Previous", 120, 200, 80, 35);
        btnNext = createButton("Next", 220, 200, 80, 35);
        btnLast = createButton("Last", 320, 200, 80, 35);

        // Initialize operation buttons
        btnNew = createButton("New", 20, 260, 80, 35);
        btnAdd = createButton("Add", 120, 260, 80, 35);
        btnUpdate = createButton("Update", 220, 260, 80, 35);
        btnDelete = createButton("Delete", 320, 260, 80, 35);

        // Add components to frame
        addComponentsToFrame();

        // Add action listeners
        addActionListeners();

        mainFrame.setLayout(null);
        mainFrame.setVisible(true);
    }

    /**
     * Create a label with specified text and position
     */
    private JLabel createLabel(String text, int x, int y) {
        JLabel label = new JLabel(text);
        label.setBounds(x, y, 100, 30);
        label.setFont(defaultFont);
        return label;
    }

    /**
     * Create a text field with specified position and size
     */
    private JTextField createTextField(int x, int y, int width) {
        JTextField textField = new JTextField();
        textField.setBounds(x, y, width, 30);
        textField.setFont(defaultFont);
        return textField;
    }

    /**
     * Create a button with specified text, position and size
     */
    private JButton createButton(String text, int x, int y, int width, int height) {
        JButton button = new JButton(text);
        button.setBounds(x, y, width, height);
        button.setFont(defaultFont);
        return button;
    }

    /**
     * Add all components to the main frame
     */
    private void addComponentsToFrame() {
        mainFrame.add(lblBookId);
        mainFrame.add(lblTitle);
        mainFrame.add(lblAuthor);
        mainFrame.add(lblPrice);

        mainFrame.add(txtBookId);
        mainFrame.add(txtTitle);
        mainFrame.add(txtAuthor);
        mainFrame.add(txtPrice);

        mainFrame.add(btnFirst);
        mainFrame.add(btnPrev);
        mainFrame.add(btnNext);
        mainFrame.add(btnLast);

        mainFrame.add(btnNew);
        mainFrame.add(btnAdd);
        mainFrame.add(btnUpdate);
        mainFrame.add(btnDelete);
    }

    /**
     * Add action listeners to all buttons
     */
    private void addActionListeners() {
        btnFirst.addActionListener(this);
        btnPrev.addActionListener(this);
        btnNext.addActionListener(this);
        btnLast.addActionListener(this);
        btnNew.addActionListener(this);
        btnAdd.addActionListener(this);
        btnUpdate.addActionListener(this);
        btnDelete.addActionListener(this);
    }

    /**
     * Connect to the MySQL database
     */
    private void connectToDatabase() {
        try {
            // Load MySQL JDBC driver
            Class.forName("com.mysql.cj.jdbc.Driver");

            // Establish database connection
            connection = DriverManager.getConnection(
                    "jdbc:mysql://localhost:3306/librarydb?useTimezone=true&serverTimezone=UTC",
                    "librarydb", "AnmolArora");

            loadBookData();
        } catch (ClassNotFoundException e) {
            showErrorMessage("MySQL JDBC Driver not found. Please ensure the driver is in the classpath.\n" +
                    "Error: " + e.getMessage(), "Driver Error");
            e.printStackTrace();
        } catch (Exception e) {
            showErrorMessage("Database connection failed. Please check:\n" +
                    "1. MySQL server is running\n" +
                    "2. Database 'librarydb' exists\n" +
                    "3. Username and password are correct\n" +
                    "Error: " + e.getMessage(), "Connection Error");
            e.printStackTrace();
        }
    }

    /**
     * Load book data from database
     */
    private void loadBookData() {
        try {
            statement = connection.createStatement(ResultSet.TYPE_SCROLL_SENSITIVE, ResultSet.CONCUR_UPDATABLE);
            resultSet = statement.executeQuery("SELECT * FROM books ORDER BY book_id");
            
            if (resultSet.next()) {
                displayCurrentBook();
            }
        } catch (Exception e) {
            showErrorMessage("Error loading book data: " + e.getMessage(), "Data Loading Error");
            e.printStackTrace();
        }
    }

    /**
     * Display current book data in the form fields
     */
    private void displayCurrentBook() {
        try {
            txtBookId.setText(resultSet.getString("book_id"));
            txtTitle.setText(resultSet.getString("title"));
            txtAuthor.setText(resultSet.getString("author"));
            txtPrice.setText(resultSet.getString("price"));
        } catch (Exception e) {
            showErrorMessage("Error displaying book data: " + e.getMessage(), "Display Error");
            e.printStackTrace();
        }
    }

    /**
     * Clear all form fields
     */
    private void clearAllFields() {
        txtBookId.setText("");
        txtTitle.setText("");
        txtAuthor.setText("");
        txtPrice.setText("");
    }

    /**
     * Add a new book to the database
     */
    private void addNewBook() {
        try {
            int bookId = Integer.parseInt(txtBookId.getText());
            String title = txtTitle.getText().trim();
            String author = txtAuthor.getText().trim();
            double price = Double.parseDouble(txtPrice.getText());

            if (title.isEmpty() || author.isEmpty()) {
                showErrorMessage("Title and Author cannot be empty!", "Validation Error");
                return;
            }

            String query = "INSERT INTO books (book_id, title, author, price) VALUES (" +
                    bookId + ", '" + title + "', '" + author + "', " + price + ")";

            System.out.println("Executing: " + query);

            int rowsAffected = statement.executeUpdate(query);
            if (rowsAffected > 0) {
                showSuccessMessage("Book added successfully!");
                loadBookData();
            }
        } catch (NumberFormatException e) {
            showErrorMessage("Please enter valid numeric values for Book ID and Price", "Input Error");
        } catch (Exception e) {
            showErrorMessage("Error adding book: " + e.getMessage(), "Database Error");
            e.printStackTrace();
        }
    }

    /**
     * Update existing book information
     */
    private void updateBook() {
        try {
            int bookId = Integer.parseInt(txtBookId.getText());
            String title = txtTitle.getText().trim();
            String author = txtAuthor.getText().trim();
            double price = Double.parseDouble(txtPrice.getText());

            if (title.isEmpty() || author.isEmpty()) {
                showErrorMessage("Title and Author cannot be empty!", "Validation Error");
                return;
            }

            String query = "UPDATE books SET title='" + title + "', author='" + author + 
                          "', price=" + price + " WHERE book_id=" + bookId;

            System.out.println("Executing: " + query);

            int rowsAffected = statement.executeUpdate(query);
            if (rowsAffected > 0) {
                showSuccessMessage("Book updated successfully!");
                loadBookData();
            } else {
                showErrorMessage("No book found with ID: " + bookId, "Update Error");
            }
        } catch (NumberFormatException e) {
            showErrorMessage("Please enter valid numeric values for Book ID and Price", "Input Error");
        } catch (Exception e) {
            showErrorMessage("Error updating book: " + e.getMessage(), "Database Error");
            e.printStackTrace();
        }
    }

    /**
     * Delete a book from the database
     */
    private void deleteBook() {
        try {
            int bookId = Integer.parseInt(txtBookId.getText());
            
            String query = "DELETE FROM books WHERE book_id=" + bookId;

            System.out.println("Executing: " + query);

            int rowsAffected = statement.executeUpdate(query);
            if (rowsAffected > 0) {
                showSuccessMessage("Book deleted successfully!");
                clearAllFields();
                loadBookData();
            } else {
                showErrorMessage("No book found with ID: " + bookId, "Delete Error");
            }
        } catch (NumberFormatException e) {
            showErrorMessage("Please enter a valid Book ID", "Input Error");
        } catch (Exception e) {
            showErrorMessage("Error deleting book: " + e.getMessage(), "Database Error");
            e.printStackTrace();
        }
    }

    /**
     * Show success message dialog
     */
    private void showSuccessMessage(String message) {
        JOptionPane.showMessageDialog(mainFrame, message, "Success", JOptionPane.INFORMATION_MESSAGE);
    }

    /**
     * Show error message dialog
     */
    private void showErrorMessage(String message, String title) {
        JOptionPane.showMessageDialog(mainFrame, message, title, JOptionPane.ERROR_MESSAGE);
    }

    /**
     * Handle button click events
     */
    @Override
    public void actionPerformed(ActionEvent e) {
        try {
            if (e.getSource() == btnNext) {
                if (resultSet.next()) {
                    displayCurrentBook();
                } else {
                    showErrorMessage("This is the last book record", "Navigation");
                }
            } else if (e.getSource() == btnPrev) {
                if (resultSet.previous()) {
                    displayCurrentBook();
                } else {
                    showErrorMessage("This is the first book record", "Navigation");
                }
            } else if (e.getSource() == btnFirst) {
                if (resultSet.first()) {
                    displayCurrentBook();
                }
            } else if (e.getSource() == btnLast) {
                if (resultSet.last()) {
                    displayCurrentBook();
                }
            } else if (e.getSource() == btnNew) {
                clearAllFields();
            } else if (e.getSource() == btnAdd) {
                addNewBook();
            } else if (e.getSource() == btnUpdate) {
                updateBook();
            } else if (e.getSource() == btnDelete) {
                deleteBook();
            }
        } catch (Exception ex) {
            showErrorMessage("An error occurred: " + ex.getMessage(), "System Error");
            ex.printStackTrace();
        }
    }

    /**
     * Main method to start the application
     */
    public static void main(String[] args) {
        // Set system look and feel
        try {
            UIManager.setLookAndFeel(UIManager.getCrossPlatformLookAndFeelClassName());
        } catch (Exception e) {
            e.printStackTrace();
        }
        
        // Start the application
        SwingUtilities.invokeLater(() -> new BookManagement());
    }
}
