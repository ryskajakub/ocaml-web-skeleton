fswatch -o -0 _build/default/hello_world.exe | xargs -0 -n 1 -I {} ./reload-server.sh {}
