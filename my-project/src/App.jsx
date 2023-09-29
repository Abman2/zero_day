import { useState } from "react";
import Inputsearch from "./component/input";
import Btn from "./component/button";

function App() {
  const [input, setInput] = useState(0);

  const inputChanges = (e) => {
    return setInput(e.target.value);
  };
  const addUp = () => {
    let sum = Number(input)+2;
    setInput(sum)
    console.log(sum)
  };

  return (
    <div className="flex justify-center items-center flex-col">
      <h1>Happy is happy</h1>
      <Inputsearch inputChange={inputChanges} valChange={input} />
      <div className="flex space-x-5">
        <Btn pholder="+" eventChange={addUp} />
        <Btn pholder="-" />
        <Btn pholder="*" />
        <Btn pholder="/" />
      </div>
    </div>
  );
}

export default App;
