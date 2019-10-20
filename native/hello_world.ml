open Lwt
open Cohttp
open Cohttp_lwt_unix

let server =
  let callback _conn req body =
    let _uri = req |> Request.uri |> Uri.to_string in
    let _meth_ = req |> Request.meth |> Code.string_of_method in
    let _headers = req |> Request.headers |> Header.to_string in
    let headers = Header.add (Header.init ()) "Content-Type" "application/json" in
    body |> Cohttp_lwt.Body.to_string >|= (fun _body ->
      ("{\"seconds\":80}"))
    >>= (fun body -> Server.respond_string ~headers ~status:`OK ~body ())
  in
  Server.create ~mode:(`TCP (`Port 6001)) (Server.make ~callback ())

let () = ignore (Lwt_main.run server)
