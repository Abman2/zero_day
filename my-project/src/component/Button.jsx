import React from 'react'

function Btn({ pholder, eventChange }) {
    return (
      <div>
        <button className="border w-10 border-red-700 " onClick={eventChange}>
          {pholder}
        </button>
      </div>
    );
  }
  
export default Btn