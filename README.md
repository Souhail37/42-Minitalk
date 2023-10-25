# 42-Minitalk
42-Cursus : Minitalk
# Client-Server Communication Program

## Description
This project involves creating a communication program consisting of both a client and a server. The server is responsible for receiving and displaying messages from clients, and the client sends messages to the server.

## Table of Contents
- [Mandatory Part](#mandatory-part)
- [Bonus Part](#bonus-part)

### Mandatory Part
- **Server Launch**: The server must be started first. After its launch, it prints its PID (Process ID).

- **Client Parameters**: The client takes two parameters:
  - The server PID (Process ID).
  - The string to send.

- **Client-Server Interaction**: The client sends the provided string as a parameter to the server. Once the string is received, the server must print it.

- **Speed**: The server has to display the received string pretty quickly. The project specifies that 1 second for displaying 100 characters is way too much.

- **Concurrency**: The server should be able to receive strings from several clients in a row without needing to restart.

- **Communication**: The communication between the client and the server is done only using UNIX signals, specifically, SIGUSR1 and SIGUSR2.

### Bonus Part
- In the bonus part, the server acknowledges every message received by sending back a signal to the client.

- For an additional challenge, consider implementing Unicode character support.
