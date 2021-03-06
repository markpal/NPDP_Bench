void sw_traco3d_128(){

printf("- traco [1x8x128x16] - \n\n");

int c1,c2,c3,c4,c5,c6,c7,c8,c9,c11,c10,c12,c13,c14,c15,c32;
/*
#pragma omp parallel for shared(N) private(c1, c2,c3,c4,c5,c6,c7,c8,c9,c11,c10,c12,c13,c14,c15)
for( c1 = 0; c1 <= (N - 1)/16; c1 += 1)
  for( c3 = 0; c3 <= (N - 1) / 16; c3 += 1)
    for( c5 = 0; c5 <= (N - 1) / 16; c5 += 1)
      for( c7 = 16 * c1 + 1; c7 <= min(N, 16 * c1 + 16); c7 += 1)
        for( c9 = 16 * c3 + 1; c9 <= min(N, 16 * c3 + 16); c9 += 1)
          for( c11 = 16 * c5 + 1; c11 <= min(N, 16 * c5 + 16); c11 += 1)

              {
               m1[c7][c9][c11] = INT_MIN;
               m2[c7][c9][c11] = INT_MIN;
               m3[c7][c9][c11] = INT_MIN;
               m4[c7][c9][c11] = INT_MIN;
               m5[c7][c9][c11] = INT_MIN;
               m6[c7][c9][c11] = INT_MIN;
              }


for( c1 = 0; c1 <= floord(N - 1, 16); c1 += 1)
#pragma omp parallel for shared(c1, N) private(c2,c3,c4,c5,c6,c7,c8,c9,c11,c10,c12,c13,c14,c15) schedule(dynamic, 1)
  for( c3 = max(0, c1 - (N + 31) / 32 + 1); c3 <= min(c1, (N - 1) / 32); c3 += 1)
    for( c5 = 0; c5 <= (N - 1) / 32; c5 += 1)
      for( c6 = 0; c6 <= 6; c6 += 1) {
        if (c6 == 6) {
          for( c9 = 32 * c1 - 32 * c3 + 1; c9 <= min(N, 32 * c1 - 32 * c3 + 32); c9 += 1)
            for( c11 = 32 * c3 + 1; c11 <= min(N, 32 * c3 + 32); c11 += 1)
              for( c13 = 32 * c5 + 1; c13 <= min(N, 32 * c5 + 32); c13 += 1) {
                for( c14 = max(0, 32 * c1 - 32 * c3 - c9 + 2); c14 <= min(1, -32 * c3 + c11 - 1); c14 += 1) {
                  if (c14 == 1) {
                    for( c15 = 1; c15 <= c11; c15 += 1)
                      m2[c9][c11][c13] = MAX(m2[c9][c11][c13], H[c9][c11-c15][c13] + W[c15]);
                  } else
                    for( c15 = 1; c15 <= c9; c15 += 1)
                      m1[c9][c11][c13] = MAX(m1[c9][c11][c13] ,H[c9-c15][c11][c13] + W[c15]);
                }
                for( c14 = max(2, 32 * c5 - c13 + 4); c14 <= min(min(3, -32 * c1 + 32 * c3 + c9 + 1), -32 * c3 + c11 + 1); c14 += 1) {
                  if (c14 == 3) {
                    for( c15 = 1; c15 <= min(c9, c11); c15 += 1)
                      m4[c9][c11][c13] = MAX(m4[c9][c11][c13], H[c9-c15][c11-c15][c13] + W[c15]);
                  } else
                    for( c15 = 1; c15 <= c13; c15 += 1)
                      m3[c9][c11][c13] = MAX(m3[c9][c11][c13], H[c9][c11][c13-c15] + W[c15]);
                }
                if (c13 >= 32 * c5 + 2)
                  for( c14 = max(4, 32 * c3 - c11 + 6); c14 <= min(5, -32 * c1 + 32 * c3 + c9 + 3); c14 += 1) {
                    if (c14 == 5) {
                      for( c15 = 1; c15 <= min(c9, c13); c15 += 1)
                        m6[c9][c11][c13] = MAX(m6[c9][c11][c13], H[c9-c15][c11][c13-c15] + W[c15]);
                    } else
                      for( c15 = 1; c15 <= min(c11, c13); c15 += 1)
                        m5[c9][c11][c13] = MAX(m5[c9][c11][c13], H[c9][c11-c15][c13-c15] + W[c15]);
                  }
                H[c9][c11][c13] = MAX(0, MAX( H[c9-1][c11-1][c13-1] + s(a[c9], b[c11], c[c13]), MAX(m1[c9][c11][c13], MAX(m2[c9][c11][c13], MAX(m3[c9][c11][c13], MAX(m4[c9][c11][c13], MAX(m5[c9][c11][c13], m6[c9][c11][c13])))))));
              }
        } else if (c6 == 5) {
          for( c7 = 0; c7 <= min(c1 - c3, c5); c7 += 1)
            for( c9 = 32 * c1 - 32 * c3 + 1; c9 <= min(N, 32 * c1 - 32 * c3 + 32); c9 += 1)
              for( c11 = 32 * c3 + 1; c11 <= min(N, 32 * c3 + 32); c11 += 1) {
                if (32 * c3 + c9 >= 32 * c1 + 2) {
                  for( c15 = 32 * c7 + 1; c15 <= min(min(32 * c5 + 1, 32 * c7 + 32), c9); c15 += 1)
                    m6[c9][c11][(32*c5+1)] = MAX(m6[c9][c11][(32*c5+1)], H[c9-c15][c11][(32*c5+1)-c15] + W[c15]);
                } else
                  for( c13 = 32 * c5 + 1; c13 <= min(N, 32 * c5 + 32); c13 += 1)
                    for( c15 = 32 * c7 + 1; c15 <= min(min(32 * c1 - 32 * c3 + 1, 32 * c7 + 32), c13); c15 += 1)
                      m6[(32*c1-32*c3+1)][c11][c13] = MAX(m6[(32*c1-32*c3+1)][c11][c13], H[(32*c1-32*c3+1)-c15][c11][c13-c15] + W[c15]);
              }
        } else if (c6 == 4) {
          for( c7 = 0; c7 <= min(c3, c5); c7 += 1)
            for( c9 = 32 * c1 - 32 * c3 + 1; c9 <= min(N, 32 * c1 - 32 * c3 + 32); c9 += 1)
              for( c11 = 32 * c3 + 1; c11 <= min(N, 32 * c3 + 32); c11 += 1) {
                if (c11 >= 32 * c3 + 2) {
                  for( c15 = 32 * c7 + 1; c15 <= min(min(32 * c5 + 1, 32 * c7 + 32), c11); c15 += 1)
                    m5[c9][c11][(32*c5+1)] = MAX(m5[c9][c11][(32*c5+1)], H[c9][c11-c15][(32*c5+1)-c15] + W[c15]);
                } else
                  for( c13 = 32 * c5 + 1; c13 <= min(N, 32 * c5 + 32); c13 += 1)
                    for( c15 = 32 * c7 + 1; c15 <= min(min(32 * c3 + 1, 32 * c7 + 32), c13); c15 += 1)
                      m5[c9][(32*c3+1)][c13] = MAX(m5[c9][(32*c3+1)][c13], H[c9][(32*c3+1)-c15][c13-c15] + W[c15]);
              }
        } else if (c6 == 3) {
          for( c7 = 0; c7 <= min(c3, c1 - c3); c7 += 1)
            for( c9 = 32 * c1 - 32 * c3 + 1; c9 <= min(N, 32 * c1 - 32 * c3 + 32); c9 += 1) {
              if (32 * c3 + c9 >= 32 * c1 + 2) {
                for( c13 = 32 * c5 + 1; c13 <= min(N, 32 * c5 + 32); c13 += 1)
                  for( c15 = 32 * c7 + 1; c15 <= min(min(32 * c3 + 1, 32 * c7 + 32), c9); c15 += 1)
                    m4[c9][(32*c3+1)][c13] = MAX(m4[c9][(32*c3+1)][c13], H[c9-c15][(32*c3+1)-c15][c13] + W[c15]);
              } else
                for( c11 = 32 * c3 + 1; c11 <= min(N, 32 * c3 + 32); c11 += 1)
                  for( c13 = 32 * c5 + 1; c13 <= min(N, 32 * c5 + 32); c13 += 1)
                    for( c15 = 32 * c7 + 1; c15 <= min(min(32 * c1 - 32 * c3 + 1, 32 * c7 + 32), c11); c15 += 1)
                      m4[(32*c1-32*c3+1)][c11][c13] = MAX(m4[(32*c1-32*c3+1)][c11][c13], H[(32*c1-32*c3+1)-c15][c11-c15][c13] + W[c15]);
            }
        } else if (c6 == 2) {
          for( c7 = 0; c7 <= c5; c7 += 1)
            for( c9 = 32 * c1 - 32 * c3 + 1; c9 <= min(N, 32 * c1 - 32 * c3 + 32); c9 += 1)
              for( c11 = 32 * c3 + 1; c11 <= min(N, 32 * c3 + 32); c11 += 1)
                for( c15 = 32 * c7 + 1; c15 <= min(32 * c5 + 1, 32 * c7 + 32); c15 += 1)
                  m3[c9][c11][(32*c5+1)] = MAX(m3[c9][c11][(32*c5+1)], H[c9][c11][(32*c5+1)-c15] + W[c15]);
        } else if (c6 == 1) {
          for( c7 = 0; c7 <= c3; c7 += 1)
            for( c9 = 32 * c1 - 32 * c3 + 1; c9 <= min(N, 32 * c1 - 32 * c3 + 32); c9 += 1)
              for( c13 = 32 * c5 + 1; c13 <= min(N, 32 * c5 + 32); c13 += 1)
                for( c15 = 32 * c7 + 1; c15 <= min(32 * c3 + 1, 32 * c7 + 32); c15 += 1)
                  m2[c9][(32*c3+1)][c13] = MAX(m2[c9][(32*c3+1)][c13], H[c9][(32*c3+1)-c15][c13] + W[c15]);
        } else
          for( c7 = 0; c7 <= c1 - c3; c7 += 1)
            for( c11 = 32 * c3 + 1; c11 <= min(N, 32 * c3 + 32); c11 += 1)
              for( c13 = 32 * c5 + 1; c13 <= min(N, 32 * c5 + 32); c13 += 1)
                for( c15 = 32 * c7 + 1; c15 <= min(32 * c1 - 32 * c3 + 1, 32 * c7 + 32); c15 += 1)
                  m1[(32*c1-32*c3+1)][c11][c13] = MAX(m1[(32*c1-32*c3+1)][c11][c13] ,H[(32*c1-32*c3+1)-c15][c11][c13] + W[c15]);
      }
*/
/*
for( c1 = 0; c1 <= floord(N - 1, 4); c1 += 1)
#pragma omp parallel for shared(c1, N) private(c2,c3,c4,c5,c6,c7,c8,c9,c11,c10,c12,c13,c14,c15) schedule(dynamic, 1)
  for( c3 = max(0, c1 - (N + 7) / 8 + 1); c3 <= min(c1, (N - 1) / 8); c3 += 1)
    for( c5 = 0; c5 <= (N - 1) / 8; c5 += 1)
      for( c6 = 0; c6 <= 6; c6 += 1) {
        if (c6 == 6) {
          for( c9 = 8 * c1 - 8 * c3 + 1; c9 <= min(N, 8 * c1 - 8 * c3 + 8); c9 += 1)
            for( c11 = 8 * c3 + 1; c11 <= min(N, 8 * c3 + 8); c11 += 1)
              for( c13 = 8 * c5 + 1; c13 <= min(N, 8 * c5 + 8); c13 += 1) {
                for( c14 = max(0, 8 * c1 - 8 * c3 - c9 + 2); c14 <= min(1, -8 * c3 + c11 - 1); c14 += 1) {
                  if (c14 == 1) {
                    for( c15 = 1; c15 <= c11; c15 += 1)
                      m2[c9][c11][c13] = MAX(m2[c9][c11][c13], H[c9][c11-c15][c13] + W[c15]);
                  } else
                    for( c15 = 1; c15 <= c9; c15 += 1)
                      m1[c9][c11][c13] = MAX(m1[c9][c11][c13] ,H[c9-c15][c11][c13] + W[c15]);
                }
                for( c14 = max(2, 8 * c5 - c13 + 4); c14 <= min(min(3, -8 * c1 + 8 * c3 + c9 + 1), -8 * c3 + c11 + 1); c14 += 1) {
                  if (c14 == 3) {
                    for( c15 = 1; c15 <= min(c9, c11); c15 += 1)
                      m4[c9][c11][c13] = MAX(m4[c9][c11][c13], H[c9-c15][c11-c15][c13] + W[c15]);
                  } else
                    for( c15 = 1; c15 <= c13; c15 += 1)
                      m3[c9][c11][c13] = MAX(m3[c9][c11][c13], H[c9][c11][c13-c15] + W[c15]);
                }
                if (c13 >= 8 * c5 + 2)
                  for( c14 = max(4, 8 * c3 - c11 + 6); c14 <= min(5, -8 * c1 + 8 * c3 + c9 + 3); c14 += 1) {
                    if (c14 == 5) {
                      for( c15 = 1; c15 <= min(c9, c13); c15 += 1)
                        m6[c9][c11][c13] = MAX(m6[c9][c11][c13], H[c9-c15][c11][c13-c15] + W[c15]);
                    } else
                      for( c15 = 1; c15 <= min(c11, c13); c15 += 1)
                        m5[c9][c11][c13] = MAX(m5[c9][c11][c13], H[c9][c11-c15][c13-c15] + W[c15]);
                  }
                H[c9][c11][c13] = MAX(0, MAX( H[c9-1][c11-1][c13-1] + s(a[c9], b[c11], c[c13]), MAX(m1[c9][c11][c13], MAX(m2[c9][c11][c13], MAX(m3[c9][c11][c13], MAX(m4[c9][c11][c13], MAX(m5[c9][c11][c13], m6[c9][c11][c13])))))));
              }
        } else if (c6 == 5) {
          for( c7 = 0; c7 <= min(c1 - c3, c5); c7 += 1)
            for( c9 = 8 * c1 - 8 * c3 + 1; c9 <= min(N, 8 * c1 - 8 * c3 + 8); c9 += 1)
              for( c11 = 8 * c3 + 1; c11 <= min(N, 8 * c3 + 8); c11 += 1) {
                if (8 * c3 + c9 >= 8 * c1 + 2) {
                  for( c15 = 8 * c7 + 1; c15 <= min(min(8 * c5 + 1, 8 * c7 + 8), c9); c15 += 1)
                    m6[c9][c11][(8*c5+1)] = MAX(m6[c9][c11][(8*c5+1)], H[c9-c15][c11][(8*c5+1)-c15] + W[c15]);
                } else
                  for( c13 = 8 * c5 + 1; c13 <= min(N, 8 * c5 + 8); c13 += 1)
                    for( c15 = 8 * c7 + 1; c15 <= min(min(8 * c1 - 8 * c3 + 1, 8 * c7 + 8), c13); c15 += 1)
                      m6[(8*c1-8*c3+1)][c11][c13] = MAX(m6[(8*c1-8*c3+1)][c11][c13], H[(8*c1-8*c3+1)-c15][c11][c13-c15] + W[c15]);
              }
        } else if (c6 == 4) {
          for( c7 = 0; c7 <= min(c3, c5); c7 += 1)
            for( c9 = 8 * c1 - 8 * c3 + 1; c9 <= min(N, 8 * c1 - 8 * c3 + 8); c9 += 1)
              for( c11 = 8 * c3 + 1; c11 <= min(N, 8 * c3 + 8); c11 += 1) {
                if (c11 >= 8 * c3 + 2) {
                  for( c15 = 8 * c7 + 1; c15 <= min(min(8 * c5 + 1, 8 * c7 + 8), c11); c15 += 1)
                    m5[c9][c11][(8*c5+1)] = MAX(m5[c9][c11][(8*c5+1)], H[c9][c11-c15][(8*c5+1)-c15] + W[c15]);
                } else
                  for( c13 = 8 * c5 + 1; c13 <= min(N, 8 * c5 + 8); c13 += 1)
                    for( c15 = 8 * c7 + 1; c15 <= min(min(8 * c3 + 1, 8 * c7 + 8), c13); c15 += 1)
                      m5[c9][(8*c3+1)][c13] = MAX(m5[c9][(8*c3+1)][c13], H[c9][(8*c3+1)-c15][c13-c15] + W[c15]);
              }
        } else if (c6 == 3) {
          for( c7 = 0; c7 <= min(c3, c1 - c3); c7 += 1)
            for( c9 = 8 * c1 - 8 * c3 + 1; c9 <= min(N, 8 * c1 - 8 * c3 + 8); c9 += 1) {
              if (8 * c3 + c9 >= 8 * c1 + 2) {
                for( c13 = 8 * c5 + 1; c13 <= min(N, 8 * c5 + 8); c13 += 1)
                  for( c15 = 8 * c7 + 1; c15 <= min(min(8 * c3 + 1, 8 * c7 + 8), c9); c15 += 1)
                    m4[c9][(8*c3+1)][c13] = MAX(m4[c9][(8*c3+1)][c13], H[c9-c15][(8*c3+1)-c15][c13] + W[c15]);
              } else
                for( c11 = 8 * c3 + 1; c11 <= min(N, 8 * c3 + 8); c11 += 1)
                  for( c13 = 8 * c5 + 1; c13 <= min(N, 8 * c5 + 8); c13 += 1)
                    for( c15 = 8 * c7 + 1; c15 <= min(min(8 * c1 - 8 * c3 + 1, 8 * c7 + 8), c11); c15 += 1)
                      m4[(8*c1-8*c3+1)][c11][c13] = MAX(m4[(8*c1-8*c3+1)][c11][c13], H[(8*c1-8*c3+1)-c15][c11-c15][c13] + W[c15]);
            }
        } else if (c6 == 2) {
          for( c7 = 0; c7 <= c5; c7 += 1)
            for( c9 = 8 * c1 - 8 * c3 + 1; c9 <= min(N, 8 * c1 - 8 * c3 + 8); c9 += 1)
              for( c11 = 8 * c3 + 1; c11 <= min(N, 8 * c3 + 8); c11 += 1)
                for( c15 = 8 * c7 + 1; c15 <= min(8 * c5 + 1, 8 * c7 + 8); c15 += 1)
                  m3[c9][c11][(8*c5+1)] = MAX(m3[c9][c11][(8*c5+1)], H[c9][c11][(8*c5+1)-c15] + W[c15]);
        } else if (c6 == 1) {
          for( c7 = 0; c7 <= c3; c7 += 1)
            for( c9 = 8 * c1 - 8 * c3 + 1; c9 <= min(N, 8 * c1 - 8 * c3 + 8); c9 += 1)
              for( c13 = 8 * c5 + 1; c13 <= min(N, 8 * c5 + 8); c13 += 1)
                for( c15 = 8 * c7 + 1; c15 <= min(8 * c3 + 1, 8 * c7 + 8); c15 += 1)
                  m2[c9][(8*c3+1)][c13] = MAX(m2[c9][(8*c3+1)][c13], H[c9][(8*c3+1)-c15][c13] + W[c15]);
        } else
          for( c7 = 0; c7 <= c1 - c3; c7 += 1)
            for( c11 = 8 * c3 + 1; c11 <= min(N, 8 * c3 + 8); c11 += 1)
              for( c13 = 8 * c5 + 1; c13 <= min(N, 8 * c5 + 8); c13 += 1)
                for( c15 = 8 * c7 + 1; c15 <= min(8 * c1 - 8 * c3 + 1, 8 * c7 + 8); c15 += 1)
                  m1[(8*c1-8*c3+1)][c11][c13] = MAX(m1[(8*c1-8*c3+1)][c11][c13] ,H[(8*c1-8*c3+1)-c15][c11][c13] + W[c15]);
      }


/*
for( c1 = 0; c1 < N + floord(N - 1, 8); c1 += 1)
#pragma omp parallel for shared(c1, N) private(c2,c3,c4,c5,c6,c7,c8,c9,c11,c10,c12,c13,c14,c15) schedule(dynamic, 1)
  for( c3 = max(0, -N + c1 + 1); c3 <= min(c1, (N - 1) / 8); c3 += 1)
    for( c5 = 0; c5 <= (N - 1) / 128; c5 += 1)
      for( c6 = 0; c6 <= 6; c6 += 1) {
        if (c6 == 6) {
          for( c11 = 8 * c3 + 1; c11 <= min(N, 8 * c3 + 8); c11 += 1)
            for( c13 = 128 * c5 + 1; c13 <= min(N, 128 * c5 + 128); c13 += 1) {
              for( c14 = max(1, 8 * c3 - c11 + 3); c14 <= min(2, -128 * c5 + c13); c14 += 1) {
                if (c14 == 2) {
                  for( c15 = 1; c15 <= c13; c15 += 1)
                    m3[(c1-c3+1)][c11][c13] = MAX(m3[(c1-c3+1)][c11][c13], H[(c1-c3+1)][c11][c13-c15] + W[c15]);
                } else
                  for( c15 = 1; c15 <= c11; c15 += 1)
                    m2[(c1-c3+1)][c11][c13] = MAX(m2[(c1-c3+1)][c11][c13], H[(c1-c3+1)][c11-c15][c13] + W[c15]);
              }
              if (c11 >= 8 * c3 + 2 && c13 >= 128 * c5 + 2)
                for( c15 = 1; c15 <= min(c11, c13); c15 += 1)
                  m5[(c1-c3+1)][c11][c13] = MAX(m5[(c1-c3+1)][c11][c13], H[(c1-c3+1)][c11-c15][c13-c15] + W[c15]);
              H[(c1-c3+1)][c11][c13] = MAX(0, MAX( H[(c1-c3+1)-1][c11-1][c13-1] + s(a[(c1-c3+1)], b[c11], c[c13]), MAX(m1[(c1-c3+1)][c11][c13], MAX(m2[(c1-c3+1)][c11][c13], MAX(m3[(c1-c3+1)][c11][c13], MAX(m4[(c1-c3+1)][c11][c13], MAX(m5[(c1-c3+1)][c11][c13], m6[(c1-c3+1)][c11][c13])))))));
            }
        } else if (c6 == 5) {
          for( c7 = 0; c7 <= min(8 * c5 + 7, (c1 - c3) / 16); c7 += 1)
            for( c11 = 8 * c3 + 1; c11 <= min(N, 8 * c3 + 8); c11 += 1)
              for( c13 = max(128 * c5 + 1, 16 * c7 + 1); c13 <= min(N, 128 * c5 + 128); c13 += 1)
                for( c15 = 16 * c7 + 1; c15 <= min(min(c1 - c3 + 1, 16 * c7 + 16), c13); c15 += 1)
                  m6[(c1-c3+1)][c11][c13] = MAX(m6[(c1-c3+1)][c11][c13], H[(c1-c3+1)-c15][c11][c13-c15] + W[c15]);
        } else if (c6 == 4) {
          for( c7 = 0; c7 <= min(8 * c5 + 7, c3 / 2); c7 += 1) {
            for( c13 = max(128 * c5 + 1, 16 * c7 + 1); c13 <= min(N, 128 * c5 + 128); c13 += 1)
              for( c15 = 16 * c7 + 1; c15 <= min(min(8 * c3 + 1, 16 * c7 + 16), c13); c15 += 1)
                m5[(c1-c3+1)][(8*c3+1)][c13] = MAX(m5[(c1-c3+1)][(8*c3+1)][c13], H[(c1-c3+1)][(8*c3+1)-c15][c13-c15] + W[c15]);
            for( c11 = 8 * c3 + 2; c11 <= min(N, 8 * c3 + 8); c11 += 1)
              for( c15 = 16 * c7 + 1; c15 <= min(min(128 * c5 + 1, 16 * c7 + 16), c11); c15 += 1)
                m5[(c1-c3+1)][c11][(128*c5+1)] = MAX(m5[(c1-c3+1)][c11][(128*c5+1)], H[(c1-c3+1)][c11-c15][(128*c5+1)-c15] + W[c15]);
          }
        } else if (c6 == 3) {
          for( c7 = 0; c7 <= min(c3 / 2, (c1 - c3) / 16); c7 += 1)
            for( c11 = 8 * c3 + 1; c11 <= min(N, 8 * c3 + 8); c11 += 1)
              for( c13 = 128 * c5 + 1; c13 <= min(N, 128 * c5 + 128); c13 += 1)
                for( c15 = 16 * c7 + 1; c15 <= min(min(c1 - c3 + 1, 16 * c7 + 16), c11); c15 += 1)
                  m4[(c1-c3+1)][c11][c13] = MAX(m4[(c1-c3+1)][c11][c13], H[(c1-c3+1)-c15][c11-c15][c13] + W[c15]);
        } else if (c6 == 2) {
          for( c7 = 0; c7 <= 8 * c5; c7 += 1)
            for( c11 = 8 * c3 + 1; c11 <= min(N, 8 * c3 + 8); c11 += 1)
              for( c15 = 16 * c7 + 1; c15 <= min(128 * c5 + 1, 16 * c7 + 16); c15 += 1)
                m3[(c1-c3+1)][c11][(128*c5+1)] = MAX(m3[(c1-c3+1)][c11][(128*c5+1)], H[(c1-c3+1)][c11][(128*c5+1)-c15] + W[c15]);
        } else if (c6 == 1) {
          for( c7 = 0; c7 <= c3 / 2; c7 += 1)
            for( c13 = 128 * c5 + 1; c13 <= min(N, 128 * c5 + 128); c13 += 1)
              for( c15 = 16 * c7 + 1; c15 <= min(8 * c3 + 1, 16 * c7 + 16); c15 += 1)
                m2[(c1-c3+1)][(8*c3+1)][c13] = MAX(m2[(c1-c3+1)][(8*c3+1)][c13], H[(c1-c3+1)][(8*c3+1)-c15][c13] + W[c15]);
        } else
          for( c7 = 0; c7 <= (c1 - c3) / 16; c7 += 1)
            for( c11 = 8 * c3 + 1; c11 <= min(N, 8 * c3 + 8); c11 += 1)
              for( c13 = 128 * c5 + 1; c13 <= min(N, 128 * c5 + 128); c13 += 1)
                for( c15 = 16 * c7 + 1; c15 <= min(c1 - c3 + 1, 16 * c7 + 16); c15 += 1)
                  m1[(c1-c3+1)][c11][c13] = MAX(m1[(c1-c3+1)][c11][c13] ,H[(c1-c3+1)-c15][c11][c13] + W[c15]);
      }
*/

/*for( c1 = 0; c1 <= floord(N - 1, 8); c1 += 1)
#pragma omp parallel for shared(c1, N) private(c2,c3,c4,c5,c6,c7,c8,c9,c11,c10,c12,c13,c14,c15) schedule(dynamic, 1)
  for( c3 = max(0, c1 - (N + 15) / 16 + 1); c3 <= min(c1, (N - 1) / 16); c3 += 1)
    for( c5 = 0; c5 <= (N - 1) / 16; c5 += 1)
      for( c6 = 0; c6 <= 6; c6 += 1) {
        if (c6 == 6) {
          for( c9 = 16 * c1 - 16 * c3 + 1; c9 <= min(N, 16 * c1 - 16 * c3 + 16); c9 += 1)
            for( c11 = 16 * c3 + 1; c11 <= min(N, 16 * c3 + 16); c11 += 1)
              for( c13 = 16 * c5 + 1; c13 <= min(N, 16 * c5 + 16); c13 += 1) {
                for( c14 = max(0, 16 * c1 - 16 * c3 - c9 + 2); c14 <= min(1, -16 * c3 + c11 - 1); c14 += 1) {
                  if (c14 == 1) {
                    for( c32 = 1; c32 <= c11; c32 += 1)
                      m2[c9][c11][c13] = MAX(m2[c9][c11][c13], H[c9][c11-c32][c13] + W[c32]);
                  } else
                    for( c32 = 1; c32 <= c9; c32 += 1)
                      m1[c9][c11][c13] = MAX(m1[c9][c11][c13] ,H[c9-c32][c11][c13] + W[c32]);
                }
                for( c14 = max(2, 16 * c5 - c13 + 4); c14 <= min(min(3, -16 * c1 + 16 * c3 + c9 + 1), -16 * c3 + c11 + 1); c14 += 1) {
                  if (c14 == 3) {
                    for( c32 = 1; c32 <= min(c9, c11); c32 += 1)
                      m4[c9][c11][c13] = MAX(m4[c9][c11][c13], H[c9-c32][c11-c32][c13] + W[c32]);
                  } else
                    for( c32 = 1; c32 <= c13; c32 += 1)
                      m3[c9][c11][c13] = MAX(m3[c9][c11][c13], H[c9][c11][c13-c32] + W[c32]);
                }
                if (c13 >= 16 * c5 + 2)
                  for( c14 = max(4, 16 * c3 - c11 + 6); c14 <= min(5, -16 * c1 + 16 * c3 + c9 + 3); c14 += 1) {
                    if (c14 == 5) {
                      for( c32 = 1; c32 <= min(c9, c13); c32 += 1)
                        m6[c9][c11][c13] = MAX(m6[c9][c11][c13], H[c9-c32][c11][c13-c32] + W[c32]);
                    } else
                      for( c32 = 1; c32 <= min(c11, c13); c32 += 1)
                        m5[c9][c11][c13] = MAX(m5[c9][c11][c13], H[c9][c11-c32][c13-c32] + W[c32]);
                  }
                H[c9][c11][c13] = MAX(0, MAX( H[c9-1][c11-1][c13-1] + s(a[c9], b[c11], c[c13]), MAX(m1[c9][c11][c13], MAX(m2[c9][c11][c13], MAX(m3[c9][c11][c13], MAX(m4[c9][c11][c13], MAX(m5[c9][c11][c13], m6[c9][c11][c13])))))));
              }
        } else if (c6 == 5) {
          for( c7 = 0; c7 <= min(c1 - c3, c5); c7 += 1)
            for( c9 = 16 * c1 - 16 * c3 + 1; c9 <= min(N, 16 * c1 - 16 * c3 + 16); c9 += 1)
              for( c11 = 16 * c3 + 1; c11 <= min(N, 16 * c3 + 16); c11 += 1) {
                if (16 * c3 + c9 >= 16 * c1 + 2) {
                  for( c32 = 16 * c7 + 1; c32 <= min(min(16 * c5 + 1, 16 * c7 + 16), c9); c32 += 1)
                    m6[c9][c11][(16*c5+1)] = MAX(m6[c9][c11][(16*c5+1)], H[c9-c32][c11][(16*c5+1)-c32] + W[c32]);
                } else
                  for( c13 = 16 * c5 + 1; c13 <= min(N, 16 * c5 + 16); c13 += 1)
                    for( c32 = 16 * c7 + 1; c32 <= min(min(16 * c1 - 16 * c3 + 1, 16 * c7 + 16), c13); c32 += 1)
                      m6[(16*c1-16*c3+1)][c11][c13] = MAX(m6[(16*c1-16*c3+1)][c11][c13], H[(16*c1-16*c3+1)-c32][c11][c13-c32] + W[c32]);
              }
        } else if (c6 == 4) {
          for( c7 = 0; c7 <= min(c3, c5); c7 += 1)
            for( c9 = 16 * c1 - 16 * c3 + 1; c9 <= min(N, 16 * c1 - 16 * c3 + 16); c9 += 1)
              for( c11 = 16 * c3 + 1; c11 <= min(N, 16 * c3 + 16); c11 += 1) {
                if (c11 >= 16 * c3 + 2) {
                  for( c32 = 16 * c7 + 1; c32 <= min(min(16 * c5 + 1, 16 * c7 + 16), c11); c32 += 1)
                    m5[c9][c11][(16*c5+1)] = MAX(m5[c9][c11][(16*c5+1)], H[c9][c11-c32][(16*c5+1)-c32] + W[c32]);
                } else
                  for( c13 = 16 * c5 + 1; c13 <= min(N, 16 * c5 + 16); c13 += 1)
                    for( c32 = 16 * c7 + 1; c32 <= min(min(16 * c3 + 1, 16 * c7 + 16), c13); c32 += 1)
                      m5[c9][(16*c3+1)][c13] = MAX(m5[c9][(16*c3+1)][c13], H[c9][(16*c3+1)-c32][c13-c32] + W[c32]);
              }
        } else if (c6 == 3) {
          for( c7 = 0; c7 <= min(c3, c1 - c3); c7 += 1)
            for( c9 = 16 * c1 - 16 * c3 + 1; c9 <= min(N, 16 * c1 - 16 * c3 + 16); c9 += 1) {
              if (16 * c3 + c9 >= 16 * c1 + 2) {
                for( c13 = 16 * c5 + 1; c13 <= min(N, 16 * c5 + 16); c13 += 1)
                  for( c32 = 16 * c7 + 1; c32 <= min(min(16 * c3 + 1, 16 * c7 + 16), c9); c32 += 1)
                    m4[c9][(16*c3+1)][c13] = MAX(m4[c9][(16*c3+1)][c13], H[c9-c32][(16*c3+1)-c32][c13] + W[c32]);
              } else
                for( c11 = 16 * c3 + 1; c11 <= min(N, 16 * c3 + 16); c11 += 1)
                  for( c13 = 16 * c5 + 1; c13 <= min(N, 16 * c5 + 16); c13 += 1)
                    for( c32 = 16 * c7 + 1; c32 <= min(min(16 * c1 - 16 * c3 + 1, 16 * c7 + 16), c11); c32 += 1)
                      m4[(16*c1-16*c3+1)][c11][c13] = MAX(m4[(16*c1-16*c3+1)][c11][c13], H[(16*c1-16*c3+1)-c32][c11-c32][c13] + W[c32]);
            }
        } else if (c6 == 2) {
          for( c7 = 0; c7 <= c5; c7 += 1)
            for( c9 = 16 * c1 - 16 * c3 + 1; c9 <= min(N, 16 * c1 - 16 * c3 + 16); c9 += 1)
              for( c11 = 16 * c3 + 1; c11 <= min(N, 16 * c3 + 16); c11 += 1)
                for( c32 = 16 * c7 + 1; c32 <= min(16 * c5 + 1, 16 * c7 + 16); c32 += 1)
                  m3[c9][c11][(16*c5+1)] = MAX(m3[c9][c11][(16*c5+1)], H[c9][c11][(16*c5+1)-c32] + W[c32]);
        } else if (c6 == 1) {
          for( c7 = 0; c7 <= c3; c7 += 1)
            for( c9 = 16 * c1 - 16 * c3 + 1; c9 <= min(N, 16 * c1 - 16 * c3 + 16); c9 += 1)
              for( c13 = 16 * c5 + 1; c13 <= min(N, 16 * c5 + 16); c13 += 1)
                for( c32 = 16 * c7 + 1; c32 <= min(16 * c3 + 1, 16 * c7 + 16); c32 += 1)
                  m2[c9][(16*c3+1)][c13] = MAX(m2[c9][(16*c3+1)][c13], H[c9][(16*c3+1)-c32][c13] + W[c32]);
        } else
          for( c7 = 0; c7 <= c1 - c3; c7 += 1)
            for( c11 = 16 * c3 + 1; c11 <= min(N, 16 * c3 + 16); c11 += 1)
              for( c13 = 16 * c5 + 1; c13 <= min(N, 16 * c5 + 16); c13 += 1)
                for( c32 = 16 * c7 + 1; c32 <= min(16 * c1 - 16 * c3 + 1, 16 * c7 + 16); c32 += 1)
                  m1[(16*c1-16*c3+1)][c11][c13] = MAX(m1[(16*c1-16*c3+1)][c11][c13] ,H[(16*c1-16*c3+1)-c32][c11][c13] + W[c32]);
      }

*/
}
