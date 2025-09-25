# Library Book Management System

A Java Swing application for managing library books with MySQL database connectivity.

## Prerequisites

1. **Java Development Kit (JDK) 11 or higher**
2. **Maven** (for dependency management)
3. **MySQL Server** (running on localhost:3306)
4. **Database Setup**: Create a database named `librarydb` with a `books` table

## Database Setup

1. Start your MySQL server
2. Create the database and table:

```sql
CREATE DATABASE librarydb;
USE librarydb;

CREATE TABLE books (
    book_id INT PRIMARY KEY,
    title VARCHAR(200) NOT NULL,
    author VARCHAR(150) NOT NULL,
    price DECIMAL(10,2) NOT NULL
);
```

3. Update the database credentials in `BookManagement.java` if needed:
   - Username: `librarydb`
   - Password: `AnmolArora`
   - Database: `librarydb`

## How to Run

### Option 1: Using Setup Script (Recommended)

1. Navigate to the DBMS directory:
   ```bash
   cd /Users/anmoldeeparora/Desktop/Anmol_college/DBMS
   ```

2. Run the setup script to download dependencies and compile:
   ```bash
   ./setup.sh
   ```

3. Run the application:
   ```bash
   ./run.sh
   ```

### Option 2: Using Maven (if Maven is installed)

1. Navigate to the DBMS directory:
   ```bash
   cd /Users/anmoldeeparora/Desktop/Anmol_college/DBMS
   ```

2. Compile and run the application:
   ```bash
   mvn compile exec:java
   ```

### Option 3: Manual Setup

1. Download the MySQL JDBC driver from:
   https://repo1.maven.org/maven2/mysql/mysql-connector-java/8.0.33/mysql-connector-java-8.0.33.jar

2. Create a `lib` directory and place the JAR file there:
   ```bash
   mkdir lib
   # Move the downloaded JAR file to lib/mysql-connector-java-8.0.33.jar
   ```

3. Compile the application:
   ```bash
   javac -cp "lib/*:src/main/java" -d build src/main/java/DBMS/BookManagement.java
   ```

4. Run the application:
   ```bash
   java -cp "lib/*:build" DBMS.BookManagement
   ```

## Features

- **Navigation**: First, Previous, Next, Last buttons to browse book records
- **CRUD Operations**:
  - **New**: Clear all fields for new entry
  - **Add**: Add new book record
  - **Update**: Modify existing book record
  - **Delete**: Remove book record
- **Error Handling**: User-friendly error messages for database connection and data validation issues
- **Input Validation**: Validates required fields and numeric inputs
- **Modern UI**: Clean and intuitive interface with proper spacing and fonts

## Troubleshooting

### Common Issues:

1. **ClassNotFoundException: com.mysql.cj.jdbc.Driver**
   - Solution: Use Maven to manage dependencies or manually add the MySQL JDBC driver to classpath

2. **Database Connection Failed**
   - Ensure MySQL server is running
   - Verify database name, username, and password
   - Check if the `books` table exists

3. **Port 3306 Connection Refused**
   - Start MySQL server
   - Check if MySQL is running on the correct port

## Project Structure

```
DBMS/
├── pom.xml                          # Maven configuration
├── README.md                        # This file
└── src/
    └── main/
        └── java/
            └── DBMS/
                └── BookManagement.java    # Main application class
```

## Dependencies

- MySQL Connector/J 8.0.33 (managed by Maven)
