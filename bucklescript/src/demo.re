open Express;

/* return the string value for [key], None if the key is not in [dict]
   TODO once BOption.map is released */
let getDictString = (dict, key) =>
  switch (Js.Dict.get(dict, key)) {
  | Some(json) => Js.Json.decodeString(json)
  | _ => None
  };

/* make a common JSON object representing success */
let makeSuccessJson = () => {
  let json = Js.Dict.empty();
  Js.Dict.set(json, "success", Js.Json.boolean(true));
  Js.Json.object_(json);
};

let app = express();

App.post(app, ~path="",
Middleware.from((_next, _req) => {
  Response.sendJson(makeSuccessJson())
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

