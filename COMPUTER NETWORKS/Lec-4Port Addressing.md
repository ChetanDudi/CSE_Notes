-->Port Addressing: A logical addressing mechanism used to identify the 
                    application/service that should receive network data on a device.
    -> Works at the Transport Layer.
    -> Used by TCP and UDP.
    ->Port Number: A 16-bit number used to identify a transport-layer endpoint.
            Range: 0 – 65535.
    -> Port is a logical, not physical, address.

    ->IP Address vs Port:
        -> IP Address: Identifies the destination host/device.
        -> Port Number: Identifies the destination application/service.
        -> Example: 192.168.1.10:443
        -> 192.168.1.10 = IP address
        -> 443 = port number

    ->Source and Destination Ports:
        -> Source Port: Port of the sending application/connection.
        -> Destination Port: Port of the receiving application/service.
        -> Both are present in TCP/UDP segments.

    ->Port Ranges:
        -> 0–1023: Well-known ports.
        -> 1024–49151: Registered ports.
        -> 49152–65535: Dynamic/private ports, commonly used as ephemeral ports.

    ->Common Ports:
        -> 20/21 → FTP
        -> 22 → SSH
        -> 25 → SMTP
        -> 53 → DNS
        -> 80 → HTTP
        -> 443 → HTTPS
        -> 3389 → RDP

    ->Ephemeral Ports: Temporary ports generally selected by the OS for outgoing 
                       connections.
        -> Example: 192.168.1.10:52341 → Server:443
            -> 52341 = client-side ephemeral port.

    ->Socket: A network communication endpoint.
        -> Commonly represented as: IP Address + Port Number
        -> Example: 192.168.1.10:5000

    ->Port and Application: A port number does not inherently belong to an application.
        -> It identifies the service/process that is listening or associated with that 
           port.
        -> Example: 443 is commonly used for HTTPS, but different web-server applications 
                    can listen on it.

    ->TCP/UDP Ports: TCP and UDP maintain separate transport protocols.
            Therefore, TCP port 443 and UDP port 443 are different endpoints.

    
-->Windows Network & Process Commands:
    netstat -ano → Shows active network connections, ports, states, and PIDs.
    netstat -ano | findstr LISTENING → Shows all currently listening ports.
    netstat -ano | findstr :5000 → Finds connections/processes using port 5000.
    tasklist → Shows all currently running processes.
    tasklist | findstr 1234 → Finds the process associated with PID 1234.
    taskkill /PID 1234 /F → Forcefully terminates the process with PID 1234.
    taskkill /IM chrome.exe /F → Forcefully terminates processes with the name chrome.exe.
    Get-NetTCPConnection → Shows TCP connections, ports, states, and owning PIDs in PowerShell.
    Get-Process → Shows currently running processes in PowerShell.
    Get-Process -Id 1234 → Shows details of the process with PID 1234.
    Resource Monitor → Network → TCP Connections → Shows active TCP connections with local/remote ports.
    Resource Monitor → Network → Listening Ports → Shows ports waiting for incoming connections.
    Use resmos in Windows search bar and go to Networks tab ot view as well