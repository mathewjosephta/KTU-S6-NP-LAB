BASICS OF NETWORK CONFIGURATION FILES AND NETWORKING COMMANDS IN LINUX

AIM

To familiarize the basics of network configuration files
and networking commands in Linux.

--------------------------------------------------

1. ifconfig

Easy Idea:

Think of it as:
"Show my network details"

Used to:
- See IP address
- Check internet connection details
- Enable or disable network

Example:

ifconfig

Like checking your phone settings for WiFi details.

--------------------------------------------------

2. ping

Easy Idea:

Checks whether another computer or website is reachable.

It sends a small message and waits for reply.

Example:

ping google.com

If reply comes:
Internet is working.

Like calling someone and checking if they answer.

--------------------------------------------------

3. traceroute

Easy Idea:

Shows the path taken by data packets.

Example:

traceroute google.com

Shows all routers between your system and Google.

Like tracking stops between your place and destination.

--------------------------------------------------

4. nslookup

Easy Idea:

Finds IP address of a website.

Example:

nslookup google.com

Like finding phone number using contact name.

--------------------------------------------------

5. SSH

Easy Idea:

Securely connects to another computer remotely.

Example:

ssh user@192.168.1.1

Like controlling another computer from your system safely.

--------------------------------------------------

6. SCP

Easy Idea:

Securely copies files between computers.

Example:

scp file.txt user@192.168.1.1:/home

Like sending files safely from one computer to another.

--------------------------------------------------

7. telnet

Easy Idea:

Used to connect to another computer remotely.

But:
It is NOT secure.

Example:

telnet localhost

Like talking openly where anyone can hear.

--------------------------------------------------

8. FTP

Easy Idea:

Used to transfer files between computers.

Example:

ftp 192.168.1.1

Like uploading or downloading files from server.

--------------------------------------------------

9. ip

Easy Idea:

Modern version of ifconfig.

Used to:
- Check IP address
- Configure network
- View routing details

Example:

ip addr show

Like advanced network settings tool.

--------------------------------------------------

10. dig

Easy Idea:

Gets detailed DNS information of websites.

Example:

dig google.com

Shows website DNS records.

Like asking internet:
"Tell me everything about this website."

--------------------------------------------------

11. netstat

Easy Idea:

Shows active network connections.

Example:

netstat -a

Displays:
- Connected systems
- Open ports
- Network status

Like checking who is connected to your system.

--------------------------------------------------

12. ss

Easy Idea:

Shows socket and network connection details.

Faster version of netstat.

Example:

ss -t

Displays TCP connections.

--------------------------------------------------

13. whois

Easy Idea:

Shows owner details of a website/domain.

Example:

whois google.com

Displays:
- Domain owner
- Registration details

Like checking vehicle owner details using number plate.

--------------------------------------------------

PRIMARY NETWORK CONFIGURATION FILES

1. /etc/hosts

Easy Idea:

Stores hostname and IP address mappings.

Example:

127.0.0.1 localhost

Like saving contact name with phone number.

--------------------------------------------------

2. /etc/resolv.conf

Easy Idea:

Stores DNS server information.

Example:

nameserver 8.8.8.8

Like saving address of internet phonebook.

--------------------------------------------------

3. /etc/sysconfig/network

Easy Idea:

Stores overall network settings of system.

Used for:
- Host details
- Routing details

--------------------------------------------------

4. /etc/nsswitch.conf

Easy Idea:

Decides where system should search information first.

Example:
Search from:
- DNS
- Hosts file
- User database

Like deciding:
"Where should I search first?"
--------------------------------------------------

IMPORTANT VIVA QUESTIONS AND ANSWERS

1. What is ifconfig?

ifconfig is used to display and configure
network interfaces.

--------------------------------------------------

2. What is ping command?

ping checks whether a host is reachable over network.

--------------------------------------------------

3. What is traceroute?

traceroute identifies the path packets take
from source to destination.

--------------------------------------------------

4. What is nslookup?

nslookup queries DNS information.

--------------------------------------------------

5. What is SSH?

SSH provides secure remote access to systems.

--------------------------------------------------

6. What is SCP?

SCP securely copies files between systems.

--------------------------------------------------

7. What is telnet?

telnet is a remote login protocol without encryption.

--------------------------------------------------

8. Why is SSH preferred over telnet?

SSH uses encryption while telnet does not.

--------------------------------------------------

9. What is FTP?

FTP is used for transferring files between systems.

--------------------------------------------------

10. Which port is used by telnet?

Port 23.
