class ha;
  logic a;
  logic b;

function new(input A, input B);
   a = A;
   b = B;
endfunction

function ha_sum;
  return a^b;
endfunction

function ha_carry;
  return a&b;
endfunction

endclass
