require "socket"

server = TCPServer.new(4242)

client = server.accept
request = client.gets

while request != "EOF"
  client.puts("Hello Client")
  request = client.gets
end

server.close
