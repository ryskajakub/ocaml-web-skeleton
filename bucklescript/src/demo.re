open Express;

let app = express();

App.post(app, ~path="",
  Middleware.from((_next, _req) => {

    let markdown_it = Markdown.markdown_it(());
    let attrs = Markdown.markdown_it_attrs;
    let () = Markdown.use(markdown_it, attrs, Js_dict.empty());

    let result = Markdown.render(markdown_it, {js|
# Header {.is-size-1}

Start of my blogisek
    |js});

    Response.sendString(result);
  }
));

App.disable(app, ~name="x-powered-by");

let onListen = e =>
  switch (e) {
  | exception (Js.Exn.Error(e)) =>
    Js.log(e);
    Node.Process.exit(1);
  | _ => Js.log @@ "Listening at http://127.0.0.1:6002"
  };

let server = App.listen(app, ~port=6002, ~onListen, ());


