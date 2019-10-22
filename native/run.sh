 _build/default/runner.exe & fswatch -o -0 _build/default/runner.exe | xargs -0 -n 1 -I {} ./reload-server.sh {}
