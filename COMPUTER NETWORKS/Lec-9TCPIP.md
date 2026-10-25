-->TCP/IP Model (Transmission Control Protocol/Internet Protocol):The TCP/IP 
        model is a networking model that describes how devices communicate over 
        interconnected networks using protocols such as TCP and IP.

-->TCP/IP stands for:
    - TCP: Transmission Control Protocol.
    - IP: Internet Protocol.
     Unlike the seven-layer OSI model, the commonly used TCP/IP model has four 
     layers.
    
    Layer 1 — Network Access Layer: The Network Access Layer, also called the 
        Link Layer, handles communication over the local network link.
        It combines responsibilities that the OSI model separates into the Data 
        Link and Physical layers.
        -->Key functions:
            - Framing: Organizes data into frames when required by the link 
              technology.
            - Link-Layer Addressing: Uses MAC addresses in technologies such as 
              Ethernet and Wi-Fi.
            - Local Delivery: Transfers frames across a local network link.
            - Error Detection: Detects transmission errors using mechanisms such 
              as Ethernet's FCS.
            - Physical Transmission: Transmits and receives bits as electrical, 
              optical, or radio signals.
            Examples: Ethernet, Wi-Fi, and PPP.

    Layer 2 — Internet Layer: The Internet Layer is responsible for addressing 
        and forwarding packets across interconnected IP networks.
        It corresponds approximately to the OSI Network Layer.
        -->Key functions:
            - Logical Addressing: Uses IPv4 and IPv6 addresses.
            - Routing: Determines paths or next hops toward destination networks.
            - Packet Forwarding: Forwards packets toward their destinations.
            - Error Reporting: Uses ICMP for certain network errors and 
              diagnostics.
            - Hop Limiting: Uses IPv4 TTL or IPv6 Hop Limit to prevent packets 
              from circulating indefinitely.
            Examples: IPv4, IPv6, and ICMP.

    Layer 3 — Transport Layer: The Transport Layer provides communication between 
        application endpoints on different devices.
        Its two most important protocols are TCP and UDP.
        -->Key functions:
            - Port Addressing: Identifies transport endpoints using port numbers.
            - Process-to-Process Delivery: Delivers data to the appropriate 
              socket.
            - Segmentation: TCP carries application data in segments.
            - Reliable Delivery: TCP provides a reliable, ordered byte stream.
            - Flow Control: TCP regulates sending according to the receiver's 
              capacity.
            - Congestion Control: TCP adjusts sending behavior in response to 
              network congestion.
            Examples: TCP and UDP.

    Layer 4 — Application Layer: The Application Layer provides the protocols 
        used by applications to communicate.
        In the four-layer TCP/IP model, it combines the responsibilities 
        associated with the Application, Presentation, and Session layers of the 
        OSI model.
        -->Key functions:
            - Web Communication: HTTP and HTTPS.
            - Name Resolution: DNS.
            - Email Communication: SMTP.
            - Remote Access: SSH.
            - Data Representation: Formats and encodings such as UTF-8.
            - Session Management: Application-level mechanisms for maintaining 
              logical sessions.
            Examples: HTTP, HTTPS, DNS, SMTP, SSH, and DHCP.