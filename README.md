# Capstone Project
This code is for my CSEC Masters Capstone Project of Spring 2023 at Rochester Institute of Technology. The program performs a MITM attack against [Ignition](https://inductiveautomation.com/) by Inductive Automation, and a PLC over Modbus/TCP.

# How to configure your environment
The test environment used was 2 Windows 10 PCs, a Linux machine, and a Cisco 3550 Multi-Layer Switch.

## Dependencies
### Packages
- `iptables` (v1.8.9 used in testing)
- `libnetfilter_queue` (v1.0.5-1 used in testing from [Arch Linux Repository](https://archlinux.org/packages/extra/x86_64/libnetfilter_queue/))
- `Python3` (3.10.10 used in the testing)
- `pip`. (v23.0 used in testing)
- Please see the [requirements.txt](./requirements.txt), and run `pip install -r requirements.txt` 

### Required Software
- [Ignition](https://inductiveautomation.com/) by Inductive Automation (v8.1.26 used in testing)
- Ignition Designer, comes packaged with Ignition and can be downloaded after installation.
- [OpenPLC WindowsRuntime](https://openplcproject.com/) by OpenPLC Project
- [FactoryIO Ultimate](https://factoryio.com/) by Real Games

## Windows Machine 1: Simulated PLC
1. Download and install [OpenPLC WindowsRuntime](https://openplcproject.com/) and [FactoryIO Ultimate](https://factoryio.com/)
	- The default settings should work just fine
2. 

## Windows Machine 2: Ignition Gateway Server