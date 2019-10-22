type markdown
type markdown_it_attrs
type markdown_it_attrs_options

external markdown_it: unit -> markdown = "markdown-it" [@@bs.module]

external markdown_it_attrs: markdown_it_attrs = "markdown-it-attrs" [@@bs.module]

external use: markdown -> markdown_it_attrs -> 'a Js_dict.t -> unit = "use" [@@bs.send]

external render: markdown -> string -> string = "render" [@@bs.send]

