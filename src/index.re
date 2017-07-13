type routes =
  | HomeRoute
  | UserRoute int;

let router =
  DirectorRe.makeRouter {
    "/": "home",
    "/user/:userID": "user"
  };

let renderForRoute route => {
  let element = switch route {
    | HomeRoute => <Home router={router} />
    | UserRoute userID => <User router={router} userID=(userID) />
  };
  ReactDOMRe.renderToElementWithId element "root";
};

let handlers = {
  "home": fun () => {
    renderForRoute HomeRoute
  },
  "user": fun (userID: string) => {
    renderForRoute (UserRoute (int_of_string userID))
  }
};

DirectorRe.configure router {"html5history": true, "resource": handlers};

DirectorRe.init router "/";
