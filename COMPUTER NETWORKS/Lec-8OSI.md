-->OSI Model (Open Systems Interconnection): The OSI Model is a conceptual 
          reference model developed by the ISO (International Organization for 
          Standardization) that divides network communication into 7 layers, with 
          each layer responsible for specific functions.
          Its main purpose is to help us understand, design, standardize, and 
          troubleshoot communication between different computer systems.

-->The Seven Layers of the OSI Model
    Layer 7: Application: Network services for applications
            -->Key Functions of the Application Layer:
                - Web Communication: Supports web requests and responses through 
                  protocols such as HTTP.
                - Name Resolution: Supports resolving domain names using DNS.
                - Email Communication: Supports sending and relaying email using 
                  SMTP.
                - File Transfer: Supports file-transfer protocols such as FTP and 
                  SFTP.
                - Remote Access: Supports remote command execution through SSH.
                - Network Configuration: Supports automatic network configuration 
                  through DHCP.
                - Application-Level Data Exchange: Defines message formats, 
                  requests, responses, and communication rules used by 
                  applications.

    Layer 6: Presentation: Data format, encryption, compression
            -->Key Functions of the Presentation Layer:
                - Data Translation: Converts or interprets data representations 
                  between compatible formats.
                - Character Encoding: Represents text using encoding standards 
                  such as UTF-8.
                - Encryption: Protects data confidentiality through cryptographic 
                  transformations.
                - Decryption: Recovers protected data for authorized use.
                - Compression: Reduces the size of data to improve storage or 
                  transmission efficiency.
                - Decompression: Reconstructs compressed data into a usable 
                  representation.
                - Data Formatting: Ensures that data is represented according to 
                  the format expected by the receiving application.

    Layer 5: Session: Manages communication sessions
            -->Key Functions of the Session Layer:
                    - Session Establishment: Initiates logical communication 
                      sessions between applications.
                    - Session Maintenance: Maintains the state of an ongoing 
                      communication session.
                    - Session Termination: Ends a session when communication is 
                      complete.
                    - Dialog Control: Coordinates communication between 
                      participants.
                    - Synchronization: Supports coordination points or 
                      checkpoints during communication where implemented.
                    - Session Recovery: Helps resume an interaction from a saved 
                      state when suitable recovery mechanisms exist.

    Layer 4: Transport: End-to-end delivery between processes
            -->Key Functions of the Transport Layer:
                - Process-to-Process Delivery: Delivers data between application 
                  endpoints on different devices.
                - Port Addressing: Uses source and destination port numbers to 
                  identify transport endpoints.
                - Segmentation and Reassembly: TCP divides a byte stream into 
                  segments and reconstructs the ordered stream at the receiver; 
                  UDP carries application data in individual datagrams.
                - Multiplexing and Demultiplexing: Allows multiple applications 
                  and transport endpoints to share the network stack and directs 
                  received data to the appropriate socket.
                - Reliable Delivery: TCP provides acknowledgments and 
                  retransmissions to deliver a reliable, ordered byte stream.
                - Flow Control: TCP regulates transmission according to the 
                  receiver's available capacity.
                - Congestion Control: TCP adjusts its sending behavior in 
                  response to network congestion.
                - Connection Management: TCP establishes and terminates 
                  connections; UDP does not establish a transport connection.

    Layer 3: Network: Logical addressing and routing
            -->Key Functions of the Network Layer:
                - Logical Addressing: Uses IP addresses to identify source and 
                  destination interfaces.
                - Routing: Determines how packets can reach destination networks.
                - Packet Forwarding: Forwards packets toward their destinations 
                  using routing or forwarding tables.
                - Internetworking: Enables communication across interconnected IP 
                  networks.
                - Fragmentation and Packet Size Handling: IPv4 routers may 
                  fragment packets when permitted and necessary; IPv6 routers do 
                  not fragment packets, leaving fragmentation to the source.
                - Hop Limiting: Uses IPv4 TTL or IPv6 Hop Limit to prevent 
                  packets from circulating indefinitely.
                - Error Reporting and Diagnostics: Works with ICMP and related 
                  mechanisms to report certain network-level problems.

    Layer 2: Data Link: Frames and local-link delivery
        -->Key Functions of the Data Link Layer:
            - Framing: Organizes the incoming bit stream into frames.
            - Physical Addressing: Uses MAC addresses for link-layer delivery.
            - Error Detection: Detects transmission errors using mechanisms such 
              as FCS/CRC.
            - Media Access Control: Determines how devices access a shared 
              transmission medium when required.
            - Flow Control: Coordinates the rate of data transmission where 
              supported by the link-layer protocol.
            - Reliable Delivery: Provides acknowledgments and retransmissions 
              where supported by the link-layer protocol.

    Layer 1: Physical: Bits and physical signals
        -->Key functions of the Physical Layer:
            - Bit transmission: Sends and receives bits over the medium.
            - Signal encoding: Defines how bits are represented by signals.
            - Data rate: Specifies supported transmission rates.
            - Physical characteristics: Defines electrical, optical, radio, 
              connector, and interface characteristics as applicable.
            - Synchronization: Supports timing needed to interpret the incoming
              bit stream.
            - Transmission mode: Standards may define whether communication is 
              simplex, half-duplex, or full-duplex.

-->Remember the order:
    - Top to bottom: Application → Presentation → Session → Transport → Network → 
      Data Link → Physical.
    - Sender: Data moves downward through the layers.
    - Receiver: Data moves upward through the layers.

