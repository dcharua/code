function M = matrizCuadrado(A)
    [f c] = size(A);
    M = zeros(f,c);
    for j = 1:f
        for k = 1:c
            M(j,k) = A(j,k)**2;
        end
    end
end
