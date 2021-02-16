class andg;
logic a;
logic b;

function new(input A, input B);
a = A;
b = B;
endfunction

function andgop;
return a&b;
endfunction
endclass
