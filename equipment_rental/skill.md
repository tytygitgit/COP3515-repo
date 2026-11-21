# Skill Name

University Equipment Inventory Report

## Purpose

This skill displays equipment inventory information for the University Equipment Rental System (UERS) by reading equipment records from an external text file.

## Project Version

Version 2.0

## Inputs

The program reads equipment information from a file named equipment.txt.

Each equipment record contains four comma-separated fields:

- Equipment ID
- Equipment Name
- Category
- Availability

Example:

1001,Laptop,Computer,true
1002,Camera,Photography,true
1003,Projector,Classroom,false

## Processing Steps

1. Display the system title and version number.
2. Open the equipment.txt file.
3. Read each record from the file.
4. Parse each record into individual fields.
5. Validate that the record contains the required data.
6. Display valid equipment records in inventory format.
7. Convert true/false availability values into Yes/No output.
8. Display an error message for invalid records.
9. Continue processing remaining records after an invalid record is found.
10. Terminate normally after all records have been processed.

## Output

The program displays:

- System title
- Version number
- Equipment inventory heading
- Equipment records loaded from the file
- Availability displayed as Yes or No
- Error messages for invalid records
- File open errors when equipment.txt cannot be found

## Constraints

Only the following Rust concepts are used:

- Cargo
- Strings
- File input
- Operators
- if statements
- match statements

The following features are not used:

- Structs
- Methods
- Searching
- Editing equipment
- Equipment checkout
- Data saving
- Databases
- Multiple inventory files

## Error Handling

The program handles the following conditions:

- Missing equipment.txt file
- Invalid equipment records
- Incorrect field counts
- Invalid availability values

When an invalid record is encountered, an error message is displayed and processing continues with the next record.

## Example Output

------------------------------------------------
University Equipment Rental System
Version 2.0
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

## Example Error Output

ERROR: Invalid equipment record

## Example Missing File Output

ERROR

Unable to open equipment.txt

Please verify that the file exists.
