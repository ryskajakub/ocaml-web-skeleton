type state = {
  seconds: int,
};

[@react.component]
let make = () => {

    let (state, dispatch) =
      React.useReducer(
        (state, action) =>
          action,
        {seconds: 30}
      );

    React.useEffect0(() => {
      Js.Promise.(
        Fetch.fetch("/api/hellos/1")
        |> then_(Fetch.Response.json)
        |> then_(json => {
          let decoded = Json.Decode.{ seconds: json |> field("seconds", int) };
          dispatch(decoded);
          decoded |> resolve
        })
        |> resolve
      );
      None
    });

    <section className="section">
      <div className="container">
        <h1 className="title">
          {ReasonReact.string("Hello World")}
        </h1>
        <p className="subtitle">
          {ReasonReact.string("My first website with ")}
          <strong>{ReasonReact.string("Bulma")}</strong>
          {ReasonReact.string("!")}
          {ReasonReact.string(string_of_int(state.seconds))}
        </p>
      </div>
    </section>;

};
