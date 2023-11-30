# linux-system-programming

## Dev Env

```bash
docker build -t linux-system-programming .
docker run -it -v $(pwd):/root/code linux-system-programming bash
```

## How to Build

```bash
make
```

And then, the output build file is `toy_system`

## How to run

After build this Makefile, run

```bash
./toy_system

# or add '&' for running toy_system in background.
./toy_system &
```

## Application Architecture

main server
--> fork --> system server
--> fork + exec --> web server(FE, BE)
--> fork + exec --> GUI (Browser)
--> fork + exec --> Input process
