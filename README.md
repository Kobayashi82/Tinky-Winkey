<div align="center">

![Security](https://img.shields.io/badge/Security-brown?style=for-the-badge)
![Service Keylogger](https://img.shields.io/badge/Service-Keylogger-blue?style=for-the-badge)
![C Language](https://img.shields.io/badge/Language-C-red?style=for-the-badge)

*A low-level Windows keylogger designed to run as a persistent background service*

</div>

<div align="center">
  <img src="/Tinky-Winkey.png">
</div>


# Tinky Winkey

[README en Español](README_es.md)

> This project is strictly for educational purposes as part of the 42 School curriculum. The code must be used only in controlled environments, such as virtual machines. Using keyloggers without proper authorization is illegal and unethical.

## 🎯 Description

This project implements a Windows service named ```tinky``` and a keylogger application named ```winkey```.  
It is an educational 42 School project designed to understand Windows service architecture, keyboard capture mechanisms, and interaction with system processes.

### 1. Service (svc.exe)

A Windows service application with the following capabilities:
- Installation and registration as a system service
- Automatic startup configuration
- Manually start and stop the service
- Service removal
- SYSTEM token impersonation
- Keylogger process management

### 2. Keylogger (winkey.exe)

A keystroke logging application that:
- Detects foreground processes
- Captures keystrokes via low-level keyboard hooks
- Logs timestamps and window titles
- Saves captured data in a readable format
- Supports locale identifiers

## Usage

### Build

```
nmake
```

### Service management

```bash
# Install the service
svc.exe install

# Start the service
svc.exe start

# Configure startup type
svc.exe config <mode>

# Service and keylogger status
svc.exe status

# Stop the service
svc.exe stop

# Delete the service
svc.exe delete
```

### Output

The keylogger generates a log file (winkey.log) with the following format:
```
[TIMESTAMP] - 'WINDOW_TITLE'
KEYSTROKES
```

## Security Notice

This project is developed exclusively for educational purposes as part of the 42 School curriculum to understand Windows systems programming concepts. The implementation must be used only in isolated environments such as virtual machines.

## 📄 License

This project is licensed under the WTFPL – [Do What the Fuck You Want to Public License](http://www.wtfpl.net/about/).

---

<div align="center">

**🔑 Developed as part of the 42 School curriculum 🔑**

*"Your secrets are safe... with me"*

</div>
