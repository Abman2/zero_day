import React from 'react'

function Inputsearch({valChange,inputChange}) {
 
    return (
      <div>
        <input
          type="number"
          className=" text-5xl  text-black border w-56 mb-4"
          value={valChange}
          onChange={inputChange}
        />
      </div>
    );
  }
export default Inputsearch