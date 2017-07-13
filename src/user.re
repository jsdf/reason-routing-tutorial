let component = ReasonReact.statelessComponent "User";

let make ::router ::userID  _children => {
  ...component,
  render: fun _self => {
    let gotoHome event => {
      ReactEventRe.Mouse.preventDefault event;
      DirectorRe.setRoute router "/";
    };

    <div>
      <h1> (ReasonReact.stringToElement ("User " ^ (string_of_int userID))) </h1>
      <a href="#" onClick={gotoHome}> (ReasonReact.stringToElement "Home") </a>
    </div>
  }
};
