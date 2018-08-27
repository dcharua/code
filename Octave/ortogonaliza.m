%Daniel Charua A01017419      04/04/17
function [VO,R] = ortogonaliza (V,eps)
  [m, n] = size(V);
  %loop para recorrer la matriz y obtener los vectores
  for k=1:m
      VO(k,:) = V(k,:);
      %Segundo loop para aplicar la formula de ortogonalizacion, del segundo vector en adelante
      for j=2:k
        VO(k,:) -= alfa(VO(j-1,:), V(k,:));
      end
  end
  %loop para recorrer la matriz resulante y eliminar los vectores cuya norma es menor al eps
  k=1;
  while k<=m
     if sum (abs(VO(k,:))) <eps
         VO(k,:) =[];
         m--;
         k--;
     end
     k++;
 end
 % se obtiene el rango de la matriz resultante
  R = rank(VO);
end

% funcion para calular alfa
function a = alfa(v1, v2)
    % si el vector es de ceros, no se hace la operacion para evitar division entre 0, se regresa alfa=0
    if sum (abs(v1)) <eps
        a = 0;
    return;
  end
  % formula para calular alfa
  a = (dot(v1, v2)/dot(v1,v1)) .* v1;
end
