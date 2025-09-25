#!/bin/bash

# Run script for Student Management System

echo "Starting Student Management System..."

# Check if MySQL JDBC driver exists
if [ ! -f "lib/mysql-connector-java-8.0.33.jar" ]; then
    echo "MySQL JDBC driver not found. Please run ./setup.sh first."
    exit 1
fi

# Check if compiled classes exist
if [ ! -d "build" ]; then
    echo "Compiled classes not found. Please run ./setup.sh first."
    exit 1
fi

# Run the application
java -cp "lib/*:build" DBMS.BookManagement
