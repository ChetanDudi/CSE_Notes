--UDP (User Datagram Protocol): It is a transport-layer protocol in the TCP/IP 
                model.
    --UDP is responsible for delivering data from an application running on 
      one device to an application running on another device using port numbers.
    --UDP handles transport between applications, while IP handles addressing and 
      routing between devices.
    --UDP does not guarantee delivery, ordering, or duplicate protection.
    --UDP allows the application to send new data without UDP itself waiting for 
      acknowledgments or retransmissions of earlier datagrams.
    --UDP is connectionless because it does not establish a transport connection 
      between the sender and receiver before sending data.
    
--UDP Header Structure:
    A UDP datagram consists of two parts:
        1. UDP header — contains information required to deliver the data to the 
           appropriate application and check its integrity.
        2. UDP payload — contains the actual data supplied by the application.
           The UDP header is only 8 bytes long, regardless of the payload size.

                                 UDP HEADER — 8 BYTES
                        0              15 16             31
                        +----------------+-----------------+
                        |   Source Port  | Destination Port|
                        |    16 bits     |    16 bits      |
                        +----------------+-----------------+
                        |     Length     |    Checksum     |
                        |    16 bits     |    16 bits      |
                        +----------------+-----------------+
                        |                                  |
                        |        UDP PAYLOAD               |
                        |     (Application Data)           |
                        |                                  |
                        +----------------------------------+
        --Length(Bytes): The Length field specifies the total length of the UDP 
                  datagram, including:
                    - The UDP header.
                    - The UDP payload.
            UDP Length=8 Bytes + Payload Length Bytes
    --UDP preserves message boundaries, but it does not guarantee that every 
      message will reach the receiver (UDP preserves datagram boundaries rather 
      than exposing a continuous byte stream).

--Key Summary:
    (1): Process-to-process delivery: Uses port numbers to help deliver data to 
         the correct application.
    (2): Multiplexing and demultiplexing: Supports communication involving 
         multiple application sockets.
    (3): Message-oriented communication: Preserves UDP datagram boundaries.
    (4): Length identification: Specifies the size of the UDP header and payload 
         together.
    (5): Error detection: Provides a checksum mechanism, subject to the rules of 
         the IP version.
    (6): Low protocol overhead: Uses a fixed 8-byte header and avoids built-in 
         connection establishment.


