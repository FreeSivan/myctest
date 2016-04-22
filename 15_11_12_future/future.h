#ifndef _FUTURE_H_
#define _FUTURE_H_

#include <pthread.h>

template <typename T>
struct Future {
public:
    Future();
    ~Future();
public:
    static void* thr(void *arg);
public:
    void assemble();
    void setContent(const T& content);
    T getContent();
    virtual T call() = 0;
private:
    T               m_content;
    pthread_mutex_t m_lock;
    pthread_cond_t  m_cond;
    bool            m_isReady;
private:
    Future(const Future<T>&);
    Future<T>& operator=(const Future<T>&);
};

template <typename T>
inline Future<T>::Future() {
    pthread_mutex_init(&m_lock, NULL);
    pthread_cond_init(&m_cond, NULL);
    m_isReady=false;
}

template <typename T>
inline Future<T>::~Future() {
    pthread_mutex_destroy(&m_lock);
    pthread_cond_destroy(&m_cond);
}

template <typename T>
inline void* Future<T>::thr(void *arg) {
    Future<T> *tmp = (Future<T>*)(arg);
    T content = tmp->call();
    tmp->setContent(content);
}

template <typename T>
inline void Future<T>::assemble() {
    pthread_t tid;
    pthread_create(&tid, 0, Future<T>::thr, (void*)this);
}

template <typename T>
inline void Future<T>::setContent(const T& content) {
    pthread_mutex_lock(&m_lock);
    if (m_isReady) {
        pthread_mutex_unlock(&m_lock);
        return;
    }
    m_content = content;
    m_isReady = true;
    pthread_cond_broadcast(&m_cond);
    pthread_mutex_unlock(&m_lock);
}

template <typename T>
inline T Future<T>::getContent() {
    pthread_mutex_lock(&m_lock);
    if (!m_isReady) {
        pthread_cond_wait(&m_cond, &m_lock);
    }
    pthread_mutex_unlock(&m_lock);
    return m_content;
}

#endif

