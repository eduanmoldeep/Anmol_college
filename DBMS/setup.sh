#!/bin/bash

# Setup script for Student Management System
# This script downloads the MySQL JDBC driver and compiles the Java application

echo "Setting up Student Management System..."

# Create lib directory for dependencies
mkdir -p lib

# Download MySQL JDBC driver (if curl is available)
if command -v curl &> /dev/null; then
    echo "Downloading MySQL JDBC driver..."
    curl -L -o lib/mysql-connector-java-8.0.33.jar \
        "https://repo1.maven.org/maven2/mysql/mysql-connector-java/8.0.33/mysql-connector-java-8.0.33.jar"
    
    if [ $? -eq 0 ]; then
        echo "MySQL JDBC driver downloaded successfully!"
    else
        echo "Failed to download MySQL JDBC driver automatically."
        echo "Please download it manually from:"
        echo "https://repo1.maven.org/maven2/mysql/mysql-connector-java/8.0.33/mysql-connector-java-8.0.33.jar"
        echo "And place it in the lib/ directory"
    fi
else
    echo "curl not found. Please download MySQL JDBC driver manually:"
    echo "https://repo1.maven.org/maven2/mysql/mysql-connector-java/8.0.33/mysql-connector-java-8.0.33.jar"
    echo "And place it in the lib/ directory"
fi

# Compile the Java application
echo "Compiling Java application..."
javac -cp "lib/*:src/main/java" -d build src/main/java/DBMS/BookManagement.java

if [ $? -eq 0 ]; then
    echo "Compilation successful!"
    echo ""
    echo "To run the application, use:"
    echo "java -cp \"lib/*:build\" DBMS.BookManagement"
    echo ""
    echo "Or simply run: ./run.sh"
else
    echo "Compilation failed. Please check the error messages above."
fi
