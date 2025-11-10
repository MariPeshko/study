This is a extended version of this exercise with IPv6 handling. get_listener_socket() returns IPv6 with IPv4-mapped addresses

> hints.ai_family = AF_INET6;     // IPv6 only

> Allow IPv4-mapped IPv6 addresses (dual-stack)
> int no = 0;  // 0 = allow IPv4-mapped, 1 = IPv6 only
> setsockopt(listener, IPPROTO_IPV6, IPV6_V6ONLY, &no, sizeof(no));

# Compile
make

# Run the server
./chat_server_cpp

# Test with multiple clients (in separate terminals)
telnet localhost 9034

# for testing IPv6
# Check what's listening now
netstat -tlnp | grep 9034

# Test IPv6 (should work now)
telnet ::1 9034

# Both should connect successfully!