#pragma once

/*
 * Неправильное планирование потоков
 */
namespace Example1
{

void worker(int id, int priority_work);
void test();

} // namespace Example1

/*
 * Неправильные приоритеты потоков
 */
namespace Example2
{

void highPriorityWorker();
void lowPriorityWorker();
void test();

} // namespace Example2

/*
 * Проблема "readers-writers" (писатели блокируют читателей)
 */
namespace Example3
{

void writer(int id);
void reader(int id);
void test();

} // namespace Example3
