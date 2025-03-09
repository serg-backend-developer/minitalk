# Minitalk

## Introduction
`Minitalk` is a project from the 42 cursus that focuses on inter-process communication (IPC) using `UNIX` signals. The objective is to create a client-server program that allows sending and receiving messages using `SIGUSR1` and `SIGUSR2` signals.

## Features
- Server that listens for incoming messages and displays them.
- Client that sends messages to the server using UNIX signals.
- Supports sending standard ASCII text.
- Implements bitwise manipulation to transmit characters via signals.

## Installation
Clone the repository and compile the project:
```sh
$ git clone https://github.com/serg-backend-developer/minitalk.git
$ cd minitalk
$ make
```

## Usage
1. Start the server:
   ```sh
   ./server
   ```
   The server will print its **Process ID (PID)**.

2. Use the client to send a message to the server:
   ```sh
   ./client <server_pid> "Your message here"
   ```
   Replace `<server_pid>` with the actual PID of the server.

## Compilation
`Minitalk` is compiled using `Makefile` with the following commands:
- `make` - Compiles the project.
- `make clean` - Removes object files.
- `make fclean` - Removes object files and binaries.
- `make re` - Recompiles the project.

## Functions Used
- `kill` - Sends signals to a process.
- `signal` / `sigaction` - Handles signals in the server.
- `pause` - Waits for signal reception.
- `usleep` - Controls signal transmission speed.
- `getpid` - Retrieves the process ID.
- `malloc`, `free`, `write` - Memory management and output handling.
