# Student Record System

This is a student record system implemented in C that allows administrators and users to manage student records.
The system utilizes file handling for storing and retrieving records.

## Features 

**Admin mode:**
* Add a student record
* Remove a student record
* View all records
* View one record
* Edit admin password
* Edit student grade

**User mode:**
* View student record
* Edit user password
* Edit user name

## File Handlig
The system uses file handling to store and retrieve student records. Records are stored in a file named __'recFile.txt'__.

## Structure
The system is structured into several files:

* __admin.h:__ Header file containing declarations related to admin operations.
* __user.h:__ Header file containing declarations related to user operations.
* __Selsct mode.h:__ Header file containing declarations for selecting the mode.
* __Struct.h:__ Header file containing the structure definition for student records.

## Usage 

*__Admin Mode:__ Upon entering the correct admin password, you can perform various administrative tasks.
*__User Mode:__ Users can view their records, edit their passwords, and edit their names after entering their IDs and passwords.



## Example
Here's an example of how to use the system:

1.__Admin Mode:__
*Enter admin mode.
*Choose an option to add, remove, view records, etc.
2.__User Mode:__
*Enter user mode.
*Enter ID and password.
*Choose an option to view or edit records.

## Feedback and Contributions
Feedback and contributions are welcome! If you encounter any issues or have suggestions for improvements, feel free to open an issue or pull request on GitHub.




