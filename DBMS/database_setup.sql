-- Database setup script for Library Book Management System
-- Run this script in your MySQL client to create the required database and table

-- Create database
CREATE DATABASE IF NOT EXISTS librarydb;

-- Use the database
USE librarydb;

-- Create books table
CREATE TABLE IF NOT EXISTS books (
    book_id INT PRIMARY KEY,
    title VARCHAR(200) NOT NULL,
    author VARCHAR(150) NOT NULL,
    price DECIMAL(10,2) NOT NULL
);

-- Insert sample data (optional)
INSERT INTO books (book_id, title, author, price) VALUES
(1, 'Introduction to Java Programming', 'Daniel Liang', 89.99),
(2, 'Clean Code: A Handbook of Agile Software Craftsmanship', 'Robert C. Martin', 45.50),
(3, 'Design Patterns: Elements of Reusable Object-Oriented Software', 'Gang of Four', 67.25),
(4, 'The Pragmatic Programmer', 'David Thomas', 52.75),
(5, 'Effective Java', 'Joshua Bloch', 78.00),
(6, 'Head First Design Patterns', 'Eric Freeman', 55.99),
(7, 'Java: The Complete Reference', 'Herbert Schildt', 95.50),
(8, 'Spring in Action', 'Craig Walls', 49.99);

-- Display the created table structure
DESCRIBE books;

-- Display sample data
SELECT * FROM books;
