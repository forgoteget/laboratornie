#include <iostream>
#include <omp.h>
#include <string>
#include <Windows.h>
#include <vector>

/*
int main()
{
	setlocale(LC_ALL, "rus");
	/* ////////////1//////////
	omp_set_num_threads(4);
	#pragma omp parallel
	{
		printf("Hello World!\n");
	}
	*/
	/*/////////////////////////2//////////
	std::cout << "Введите количество нитей: ";
	int n = 0;
	std::cin >> n;
	omp_set_num_threads(n);
	#pragma omp parallel
	{
		printf("I am %d thread from %d threads!\n", omp_get_thread_num(), omp_get_num_threads());
	}*/


    /*
    * ///////////////////////////////////////////////3//
    std::cout << "Введите количество нитей: ";
    int n = 0;
    std::cin >> n;

    // shared
    omp_set_num_threads(n);
    int s_rank;
#pragma omp parallel shared(s_rank)
    {
        s_rank = omp_get_thread_num();
        Sleep(100); // Имитация длительных вычислений
        //std::cout << "I`m " << s_rank << " thread(shared)\n";
        std::printf("I'm %d thread(shared)\n", s_rank);
    }

    // private
    omp_set_num_threads(n);
    int p_rank;
    #pragma omp parallel private(p_rank)
    {
        p_rank = omp_get_thread_num();
        Sleep(100); // Имитация длительных вычислений
        //std::cout << "I`m " << p_rank << " thread(private)\n";
        std::printf("I'm %d thread(private)\n", p_rank);
    }

    // general
    omp_set_num_threads(n);
    int g_rank;
    #pragma omp parallel
    {
        g_rank = omp_get_thread_num();
        Sleep(100); // Имитация длительных вычислений
        //std::cout << "I`m " << g_rank << " thread(general)\n";
        std::printf("I'm %d thread(general)\n", g_rank);
    }
    */

    /*
    * //////////////////////////////////////5//
    std::cout << "Введите количество нитей: ";
    int k = 0;
    std::cin >> k;
    std::cout << "Введите количество чисел: ";
    int n = 0;
    std::cin >> n;
    int sum = 0;
    int i = 0;
    omp_set_num_threads(k);
    #pragma omp parallel reduction(+:sum) private(i)
    {
        for (i = omp_get_thread_num(); i <= n; i = i + omp_get_num_threads())
        {
            sum += i;
        }
        std::printf("Im %d sum:", omp_get_thread_num());
        std::printf("%d \n", sum);
//        std::cout << "Im " << omp_get_thread_num() << " sum: " << sum << std::endl;
    }
    std::cout << "Общая сумма " << sum << "\n";
    */

    /*
    std::cout << "Введите количество нитей: ";
    int k = 0;
    std::cin >> k;
    std::cout << "Введите количество чисел: ";
    int n = 0;
    std::cin >> n;
    int sum = 0;
    omp_set_num_threads(k);
#pragma omp parallel reduction(+:sum)
    {
#pragma omp  for
        for (int i = 1; i <= n; i++)
        {
            sum += i;
        }
        //std::cout << "Im " << omp_get_thread_num() << " sum: " << sum << "\n";
        std::printf("I'm %d sum: ", omp_get_thread_num());
        std::printf("%d\n", sum);
    }
    std::cout << "Общая сумма " << sum << "\n";
    */

    /*std::cout << "Введите количество нитей: ";
    int k = 0;
    std::cin >> k;
    int n = 10;
    int sum = 0;
    omp_set_num_threads(k);
    int i;

    std::cout << "Static without parameters\n";
#pragma omp parallel reduction(+:sum) private(i)
    {
#pragma omp for schedule(static)
        for (i = 1; i <= n; i++)
        {
            sum += i;
            std::cout << "Im " << omp_get_thread_num() << " calculation of the iteration number: " << i << "\n";
        }
    }

    std::cout << "Static is inputed 1\n";
#pragma omp parallel reduction(+:sum) private(i)
    {
#pragma omp for schedule(static,1)
        for (i = 1; i <= n; i++)
        {
            sum += i;
            std::cout << "Im " << omp_get_thread_num() << " calculation of the iteration number: " << i << "\n";
        }
    }

    std::cout << "Static is inputed 2\n";
#pragma omp parallel reduction(+:sum) private(i)
    {
#pragma omp for schedule(static,2)
        for (i = 1; i <= n; i++)
        {
            sum += i;
            std::cout << "Im " << omp_get_thread_num() << " calculation of the iteration number: " << i << "\n";
        }
    }

    // dynamic
    std::cout << "dynamic without parameters\n";
#pragma omp parallel reduction(+:sum) private(i)
    {
#pragma omp for schedule(dynamic)
        for (i = 1; i <= n; i++)
        {
            sum += i;
            std::cout << "Im " << omp_get_thread_num() << " calculation of the iteration number: " << i << "\n";
        }
    }

    std::cout << "dynamic is inputed 1\n";
#pragma omp parallel reduction(+:sum) private(i)
    {
#pragma omp for schedule(dynamic,1)
        for (i = 1; i <= n; i++)
        {
            sum += i;
            std::cout << "Im " << omp_get_thread_num() << " calculation of the iteration number: " << i << "\n";
        }
    }

    std::cout << "dynamic is inputed 2\n";
#pragma omp parallel reduction(+:sum) private(i)
    {
#pragma omp for schedule(dynamic,2)
        for (i = 1; i <= n; i++)
        {
            sum += i;
            std::cout << "Im " << omp_get_thread_num() << " calculation of the iteration number: " << i << "\n";
           
        }
    }

    // guided
    std::cout << "guided without parameters\n";
#pragma omp parallel reduction(+:sum) private(i)
    {
#pragma omp for schedule(guided)
        for (i = 1; i <= n; i++)
        {
            sum += i;
            std::cout << "Im " << omp_get_thread_num() << " calculation of the iteration number: " << i << "\n";
       
        }
    }

    std::cout << "guided is inputed 2\n";
#pragma omp parallel reduction(+:sum) private(i)
    {
#pragma omp for schedule(guided,2)
        for (i = 1; i <= n; i++)
        {
            sum += i;
            std::cout << "Im " << omp_get_thread_num() << " calculation of the iteration number: " << i << "\n";
           
        }
    }*/

   /*
    std::cout << "Точность вычисления: ";
    int k = 0;
    std::cin >> k;
    double pi = 0.0;
    for (int i = 0; i <= k; i++)
    {
        pi = pi + 4 / (1 + ((i + 0.5) / k) * ((i + 0.5) / k));
    }
    pi /= k;
    std::cout << "Пи равен (без параллелизации) " << pi << "\n";

    // параллелизируем
    pi = 0.0;
    omp_set_num_threads(10);
    int i = 0;
#pragma omp parallel reduction(+:pi) shared(i)
    {
#pragma omp for
        for (i = 0; i <= k; i++)
        {
            pi = pi + 4 / (1 + ((i + 0.5) / k) * ((i + 0.5) / k));
        }

        std::cout << "Im " << omp_get_thread_num() << " частичная сумма Пи равен " << pi << "\n";
    }
    pi /= k;
    std::cout << "Пи равен (c параллелизации) " << pi << "\n";*/

    /*
    std::cout << "Введите количество нитей: ";
    int k = 0;
    std::cin >> k;
    std::cout << "Введите количество чисел: ";
    int n = 0;
    std::cin >> n;
    int sum = 0;
    int i = 0;
    omp_set_num_threads(k);
    #pragma omp parallel  private(i)
    {
        for (i = omp_get_thread_num(); i <= n; i = i + omp_get_num_threads())
        {
    #pragma omp atomic
            sum += i;
        }
        //std::cout << "Im " << omp_get_thread_num() << " sum: " << sum << "\n";
        std::printf("I'm %d  sum:", omp_get_thread_num());
        std::printf("%d \n", sum);
    }
    std::cout << "Общая сумма " << sum << "\n";
    
    


	return 0;
}
*/
double** a;
double** b;
double** c;
void matrix(int k, int n)
{
    if (n == 100)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                c[i][j] = 0.0;
            }
        }
        std::random_device rd;
        std::mt19937 gen(rd());
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                a[i][j] = gen();
                b[i][j] = gen();
            }
        }
        double start = omp_get_wtime();
        omp_set_num_threads(k);
#pragma omp parallel
        {
#pragma omp for
            for (int i = 0; i < n; i++)
            {
#pragma omp parallel
#pragma omp for
                for (int j = 0; j < n; j++)
                {
#pragma omp parallel
                    {
#pragma omp for
                        for (int k = 0; k < n; k++)
                        {
                            c[i][j] += a[i][k] * b[k][j];
                        }
                    }
                }
            }
        }
        double end = omp_get_wtime();
        std::cout << "Time = " << end - start << " n: " << n << " k: " << k << "\n";
    }
    else
    {
        int kom = 10;
        double sum = 0.0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                c[i][j] = 0.0;
            }
        }
        std::random_device rd;
        std::mt19937 gen(rd());
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                a[i][j] = gen();
                b[i][j] = gen();
            }
        }
        for (int pov = 0; pov < kom; pov++)
        {
            double start = omp_get_wtime();
            omp_set_num_threads(k);
#pragma omp parallel
            {
#pragma omp for
                for (int i = 0; i < n; i++)
                {
#pragma omp parallel
#pragma omp for
                    for (int j = 0; j < n; j++)
                    {
#pragma omp parallel
                        {
#pragma omp for
                            for (int k = 0; k < n; k++)
                            {
                                c[i][j] += a[i][k] * b[k][j];
                            }
                        }
                    }
                }
            }
            double end = omp_get_wtime();
            sum = sum + (end - start);
        }
        std::cout << "Time = " << sum * (1000 / kom) << " n: " << 1000000 << " k: " << k << "\n";
    }
    return;
}
int main()
{
    std::vector<int> N = { 100,1000 };
    std::vector<int> K = { 1,2,4,6,8,10,12 };
    int n = 1000;

    a = (double**)malloc(n * sizeof(double*));
    b = (double**)malloc(n * sizeof(double*));
    c = (double**)malloc(n * sizeof(double*));
    for (int i = 0; i < n; i++)
    {
        *(a + i) = (double*)malloc(n * sizeof(double));
        *(b + i) = (double*)malloc(n * sizeof(double));
        *(c + i) = (double*)malloc(n * sizeof(double));
    }
    for (auto i = K.begin(); i < K.end(); i++)
    {
        for (auto j = N.begin(); j < N.end(); j++)
        {
            matrix(*i, *j);
        }
    }
    for (int i = 0; i < n; i++)
    {
        free(a + i);
        free(b + i);
        free(c + i);
    }
    free(a);
    free(b);
    free(c);
}