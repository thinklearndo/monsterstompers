const http = require('http');
var player = require('play-sound')(opts = {})

const hostname = '0.0.0.0';
const port = 3000;

const server = http.createServer((req, res) => {
  player.play('stomp.mp3', function(err){
    if (err) throw err
  })
  res.statusCode = 200;
  res.setHeader('Content-Type', 'text/plain');
  res.end('OK');
});

server.listen(port, hostname, () => {
  console.log(`Server running at http://${hostname}:${port}/`);
});
