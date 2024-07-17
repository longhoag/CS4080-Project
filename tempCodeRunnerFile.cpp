auto start = high_resolution_clock::now();
    float** res = multiplyMatrices(mat1, mat2, size, size, size, size);
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: " << duration.count() << " microseconds" << endl;