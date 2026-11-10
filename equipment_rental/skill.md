# Skill Name

University Equipment Inventory Report

## Purpose

This skill displays a simple equipment inventory report for the University Equipment Rental System (UERS).

## Project Version

Version 1.0

## Inputs

The program uses hard-coded equipment information.

Each equipment record contains:

- Equipment ID
- Equipment Name
- Category
- Availability

## Processing Steps

1. Store three equipment records using variables.
2. Display the system title.
3. Display the version number.
4. Display the equipment inventory report.
5. Convert availability values from true/false into Yes/No output.

## Output

The program displays:

- System title
- Version number
- Equipment inventory heading
- Three equipment records
- Availability displayed as Yes or No

## Constraints

Only the following Rust concepts are used:

- Cargo
- Comments
- Variables
- Primitive data types
- Boolean values
- println!() formatting

The following features are not used:

- User input
- Files
- Structs
- Functions
- Methods
- Vectors
- Searching
- Editing equipment
- Equipment checkout
- Data saving

## Example Output

------------------------------------------------
University Equipment Rental System
Version 1.0
------------------------------------------------

Equipment Inventory

ID:          1001
Name:        Laptop
Category:    Computer
Available:   Yes

ID:          1002
Name:        Camera
Category:    Photography
Available:   Yes

ID:          1003
Name:        Projector
Category:    Classroom
Available:   No
