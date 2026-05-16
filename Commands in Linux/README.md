BASICS OF NETWORK CONFIGURATION FILES AND NETWORKING COMMANDS IN LINUX

AIM

To familiarize the basics of network configuration files
and networking commands in Linux. :contentReference[oaicite:0]{index=0}

--------------------------------------------------

FIRST UNDERSTAND THIS FLOW

1. Check your network details
2. Check internet connection
3. Find website IP address
4. Track packet path
5. View active connections
6. Connect to remote systems
7. Transfer files
8. Understand configuration files

--------------------------------------------------

1. ifconfig

Easy Idea:

Shows your network details.

Used to:
- View IP address
- Check WiFi/Ethernet details
- Enable or disable network

Example:

ifconfig

Like opening phone settings and checking WiFi details.

--------------------------------------------------

2. ip

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

3. ping

Easy Idea:

Checks whether internet or another system is reachable.

Example:

ping google.com

If reply comes:
Internet is working.

Like calling someone and checking if they answer.

--------------------------------------------------

4. nslookup

Easy Idea:

Finds IP address of a website.

Example:

nslookup google.com

Like searching contact number using name.

--------------------------------------------------

5. dig

Easy Idea:

Shows detailed DNS information of websites.

Example:

dig google.com

Like asking internet:
"Give full details about this website."

--------------------------------------------------

6. traceroute

Easy Idea:

Shows the path taken by packets from source to destination.

Example:

traceroute google.com

Shows all routers between your system and Google.

Like tracking all bus stops before reaching destination.

--------------------------------------------------

7. netstat

Easy Idea:

Shows active network connections.

Example:

netstat -a

Displays:
- Connected systems
- Open ports
- Network status

Like checking who is connected to your network.

--------------------------------------------------

8. ss

Easy Idea:

Shows socket and connection details.

Faster version of netstat.

Example:

ss -t

Displays TCP connections.

--------------------------------------------------

9. SSH

Easy Idea:

Securely connects to another computer remotely.

Example:

ssh user@192.168.1.1

Like controlling another computer safely from your system.

--------------------------------------------------

10. telnet

Easy Idea:

Used to remotely connect to another computer.

But:
Not secure because data is not encrypted.

Example:

telnet localhost

Like talking publicly where anyone can listen.

--------------------------------------------------

11. SCP

Easy Idea:

Securely transfers files between computers.

Example:

scp file.txt user@192.168.1.1:/home

Like securely sending files to another computer.

--------------------------------------------------

12. FTP

Easy Idea:

Transfers files between systems.

Example:

ftp 192.168.1.1

Like uploading/downloading files from server.

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

--------------------------------------------------

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

Like storing address of internet phonebook.

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

Decides where Linux should search information first.

Example:
Search from:
- DNS
- Hosts file
- User database

Like deciding:
"Where should I search first?"
