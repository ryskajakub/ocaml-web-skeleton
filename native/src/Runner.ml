open Lwt
open Cohttp_lwt_unix
open Cohttp_lwt

type tt = {
  x: string ;
} [@@deriving yojson]

let server =
  let callback _conn request (request_body: Body.t) =
    let request_uri: string = Uri.path @@ Request.uri request in

    let body: string Lwt.t = Body.to_string request_body in 

    body >>= (fun bbb ->

      let string: string = Yojson.Safe.to_string @@ yojson_of_tt ({ x = "lolol"}) in

      let parsed: tt = tt_of_yojson @@ Yojson.Safe.from_string bbb in

      let result = match request_uri with 
        | "/path" -> "lolol"
        | "/path2" -> "XXXX"
        | "/olol" -> string
        | _ -> parsed.x
        in

      Server.respond_string ~status:`OK ~body:result ()
    )
    (*
      Client.post (Uri.of_string "http://localhost:6002") >>=
      (fun (_response, body) -> Server.respond ~status:`OK ~body ())
      let _uri = req |> Request.uri |> Uri.to_string in
      let _meth_ = req |> Request.meth |> Code.string_of_method in
      let _headers = req |> Request.headers |> Header.to_string in
      let headers = Header.add (Header.init ()) "Content-Type" "application/json" in
      body |> Cohttp_lwt.Body.to_string >|= (fun _body ->
        ("{\"seconds\":80}"))
      >>= (fun body -> Server.respond_string ~headers ~status:`OK ~body ())
    *)
  in
  Server.create ~mode:(`TCP (`Port 6001)) (Server.make ~callback ())

let () = ignore (Lwt_main.run server)
