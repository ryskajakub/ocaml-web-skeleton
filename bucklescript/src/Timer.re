type state = {
  html: string,
};

type html = {
  .
  __html: string
};

[@react.component]
let make = () => {

    let (state, dispatch) =
      React.useReducer(
        (_state, action) =>
          { html: action.html },
        { html: "" }
      );

    React.useEffect0(() => {
      Js.Promise.(
        Fetch.fetch("/api/")
        |> then_(Fetch.Response.text)
        |> then_(text => {
          let decoded = { html: text };
          dispatch(decoded) |> resolve;
        })
      ) |> ignore;
      None
    });

    let dang = { "__html": state.html };

    <section className="section">
      <div className="container" dangerouslySetInnerHTML={dang}>
      </div>
    </section>;

};
