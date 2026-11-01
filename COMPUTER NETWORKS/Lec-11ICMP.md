--ICMP (Internet Control Message Protocol): It is a network-layer supporting   
        protocol used by network devices to communicate information about IP    
        packet delivery, errors, and network conditions.
        --ICMP does not carry your ordinary application data, such as the 
          contents of a web page. Its primary purpose is to provide network-layer 
          control, error reporting, and diagnostic information.
--Why do we need ICMP?
    Consider what IP does:The Internet Protocol (IP) provides best-effort packet 
             delivery. It tries to deliver packets to their destinations, but it 
             does not guarantee that every packet will arrive.
    Packets can fail to reach their destinations for several reasons:
        - The destination network is unreachable.
        - The destination host is unreachable.
        - A packet's Time to Live (TTL) expires.
        - A router cannot forward a packet because of certain network conditions.
        - A packet is too large for a link and cannot be fragmented because 
            fragmentation is prohibited.
    IP itself does not provide a general mechanism for communicating all these 
       error conditions to the original sender.
    ICMP helps fill that gap.

--ICMP Packet flow:
    Step 1: Your computer creates the packet:Your computer prepares an ICMP Echo 
            Request and places it inside an IPv4 packet.
            The IPv4 header contains the source and destination IP addresses.
            The IPv4 Protocol field identifies the payload as ICMP using the 
            value 1.
    Step 2: The packet is forwarded: Your computer sends the packet toward the 
            destination.
            Routers examine the destination IP address and their routing tables 
            to decide where to forward it.
    Step 3: A device may generate an ICMP message: If a router encounters a 
            condition that calls for an ICMP error, it can generate a new ICMP 
            packet addressed to the original sender.
            For example, if the packet's TTL expires, a router can generate an 
            ICMP Time Exceeded message.
    Step 4: The destination may reply: If the destination receives an Echo 
            Request and is configured to respond, it sends an Echo Reply.
            The reply travels back toward your computer.
    Important: The router does not normally change the original packet into an 
            ICMP error message. It discards the packet when required and creates 
            a separate ICMP message reporting the problem.

--ICMP with Ping: The ping command uses ICMP Echo Request and Echo Reply messages 
            to check whether a destination is reachable.
        Echo Request (Type 8): Sent by the source to the destination.
        Echo Reply (Type 0): Sent by the destination in response to the request.
        Round-Trip Time (RTT): Measures the time taken for a request to reach the 
              destination and its reply to return.
        Note: A failed ping does not necessarily mean the destination is offline; 
              ICMP traffic may be blocked by a firewall.

--ICMP with Tracert: The tracert command in Windows identifies the routers that 
             respond along the path to a destination. It progressively increases 
             the TTL (Time to Live) value of its probes.
        TTL = 1: The first router typically returns an ICMP Time Exceeded 
                 message.
        TTL = 2: The second router typically returns an ICMP Time Exceeded 
                 message.
        The process continues until the destination is reached or the maximum hop 
             limit is exceeded.
        Time Exceeded (Type 11): Indicates that the probe's TTL expired during 
             forwarding.
--Note: * * * indicates that no response was received within the timeout period. 
        The router may still be forwarding packets normally. or ICMP requests are 
        blocked by that router.

--An ICMP packet is carried inside an IP packet. For an Echo Request, the 
     structure is:
                    ┌─────────────────────────────────────────────┐
                    │                 IPv4 HEADER                 │
                    ├─────────────────────────────────────────────┤
                    │ Source IP Address      : 192.168.1.10       │
                    │ Destination IP Address : 8.8.8.8            │
                    │ Protocol               : 1 (ICMP)           │
                    │ TTL                    : 128                │
                    └─────────────────────────────────────────────┘
                    ┌─────────────────────────────────────────────┐
                    │                 ICMP HEADER                 │
                    ├─────────────────────────────────────────────┤
                    │ Type                   : 8                  │
                    │ Code                   : 0                  │
                    │ Checksum               : 0xABCD (example)   │
                    │ Identifier             : 0x0001             │
                    │ Sequence Number        : 1                  │
                    └─────────────────────────────────────────────┘
                    ┌─────────────────────────────────────────────┐
                    │                 ICMP DATA                   │
                    ├─────────────────────────────────────────────┤
                    │ Payload                : 32 bytes (example) │
                    │ Example data           : 00 01 02 03 ...    │
                    └─────────────────────────────────────────────┘

Field	         Size	                     Description
Type	        1 byte	  Identifies the ICMP message. Type 8 means Echo Request.
Code	        1 byte	  Further specifies the message. Code 0 is used for Echo 
                          Request.
Checksum	    2 bytes	  Detects corruption in the ICMP message.
Identifier	    2 bytes	  Helps associate requests with their corresponding 
                          replies.
Sequence Number	2 bytes	  Distinguishes individual requests, such as request 1 
                          and request 2.
Data/Payload	Variable  Contains the data sent with the Echo Request.

--The ICMP header is 8 bytes, and the data is 32 bytes. Therefore: Total ICMP 
      message size = 8 + 32 = 40 bytes.