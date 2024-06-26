# Dispatcher

`Dispatcher` is a simple scheduler test application developed using the Qt framework. The application simulates basic process management functionalities, including creating, switching, blocking, unblocking, and deleting processes. It provides a graphical user interface to manage and visualize these processes.

## Features

- **Create New Process**: Add new processes to the scheduler.
- **Trigger Switch**: Switch the currently running process to the ready state.
- **Block Process**: Block a specified process by its ID.
- **Un-Block Process**: Unblock a specified process by its ID.
- **Delete Process**: Delete a specified process by its ID.
- **Process Visualization**: Display processes in different states (Running, Ready, Blocked) using tables and lists.

## Screenshots

![Dispatcher Screenshot](path/to/screenshot.png)

## Installation

### Prerequisites

- Qt 5.x or later
- Qt Creator (optional, for development)

### Clone the Repository

```bash
git clone https://github.com/username/dispatcher.git
cd dispatcher
```

### Build and Run

#### Using Qt Creator

1. Open `dispatcher.pro` in Qt Creator.
2. Configure the project if prompted.
3. Click the "Build" button (hammer icon) to compile the project.
4. Click the "Run" button (green play icon) to launch the application.

#### Using Command Line

1. Open a terminal (or Command Prompt/PowerShell on Windows).
2. Navigate to the project directory.
3. Generate Makefiles with qmake:
   ```bash
   qmake dispatcher.pro
   ```
4. Build the project:
   ```bash
   make
   # or on Windows with MinGW
   mingw32-make
   ```
5. Run the application:
   ```bash
   ./dispatcher
   # or on Windows
   dispatcher.exe
   ```

## Usage

### Creating a New Process

1. Click the "Create New Process" button to add a new process to the scheduler.
2. The new process will appear in the "Processes" table and the "Ready Queue".

### Switching Processes

1. Click the "Trigger Switch" button to switch the currently running process to the ready state.
2. The process state will be updated in the "Processes" table.

### Blocking a Process

1. Enter the process ID in the "Block Process" input field.
2. Click the "Block Process" button to change the state of the specified process to "Blocked".
3. The process will move from the "Ready Queue" to the "Blocked List".

### Unblocking a Process

1. Enter the process ID in the "Un-Block Process" input field.
2. Click the "Un-Block Process" button to change the state of the specified process to "Ready".
3. The process will move from the "Blocked List" to the "Ready Queue".

### Deleting a Process

1. Enter the process ID in the "Delete Process" input field.
2. Click the "Delete Process" button to remove the specified process from the scheduler.
3. The process will be removed from all relevant tables and lists.

## Project Structure

- `mainwindow.h` and `mainwindow.cpp`: Define and implement the main window and its functionalities.
- `scheduler.h` and `scheduler.cpp`: Define and implement the process and scheduler logic.
- `ui_mainwindow.h`: Generated by Qt Designer, contains UI components.

## License

This project is licensed under the MIT License. See the LICENSE file for details.
