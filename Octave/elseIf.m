function f = elseIf(a,b,op)
  if op== 0
    f=a+b;
  elseif op==1
    f=a*b;
  elseif op==2
    f=a-b;
  else
    f=a/b;
    end
end
