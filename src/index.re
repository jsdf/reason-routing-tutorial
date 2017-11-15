type routes =
  | HomeRoute
  | UserRoute(int);

let router = DirectorRe.makeRouter({
  "/": "home",
  "/user/:userID": "user"
});

let renderForRoute = (route) => {
  let element =
    switch route {
    | HomeRoute => <Home router />
    | UserRoute(userID) => <User router userID />
    };
  ReactDOMRe.renderToElementWithId(element, "root")
};

let handlers = {
  "home": () => renderForRoute(HomeRoute),
  "user": (userID: string) => renderForRoute(UserRoute(int_of_string(userID)))
};

DirectorRe.configure(router, {
  "html5history": true,
  "resource": handlers
});

DirectorRe.init(router, "/");
