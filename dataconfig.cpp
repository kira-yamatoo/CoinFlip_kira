#include "dataconfig.h"
#include <QDebug>

DataConfig::DataConfig(QObject *parent) : QObject(parent)
{
    int array1[4][4] = { {1, 1, 1, 1},
                         {1, 1, 0, 1},
                         {1, 0, 0, 0},
                         {1, 1, 0, 1} } ;

    int array2[4][4] = { {1, 0, 1, 1},
                         {0, 0, 1, 1},
                         {1, 1, 0, 0},
                         {1, 1, 0, 1}} ;

    int array3[4][4] = {  {0, 0, 0, 0},
                          {0, 1, 1, 0},
                          {0, 1, 1, 0},
                          {0, 0, 0, 0}} ;

    int array4[4][4] = {   {0, 1, 1, 1},
                           {1, 0, 0, 1},
                           {1, 0, 1, 1},
                           {1, 1, 1, 1}} ;

    int array5[4][4] = {  {1, 0, 0, 1},
                          {0, 0, 0, 0},
                          {0, 0, 0, 0},
                          {1, 0, 0, 1}} ;


    int array6[4][4] = {   {1, 0, 0, 1},
                           {0, 1, 1, 0},
                           {0, 1, 1, 0},
                           {1, 0, 0, 1}} ;

    int array7[4][4] = {   {0, 1, 1, 1},
                           {1, 0, 1, 1},
                           {1, 1, 0, 1},
                           {1, 1, 1, 0}} ;

    int array8[4][4] = {  {0, 1, 0, 1},
                          {1, 0, 0, 0},
                          {0, 0, 0, 1},
                          {1, 0, 1, 0}} ;

    int array9[4][4] = {   {1, 0, 1, 0},
                           {1, 0, 1, 0},
                           {0, 0, 1, 0},
                           {1, 0, 0, 1}} ;

    int array10[4][4] = {  {1, 0, 1, 1},
                           {1, 1, 0, 0},
                           {0, 0, 1, 1},
                           {1, 1, 0, 1}} ;

    int array11[4][4] = {  {0, 1, 1, 0},
                           {1, 0, 0, 1},
                           {1, 0, 0, 1},
                           {0, 1, 1, 0}} ;

    int array12[4][4] = {  {0, 1, 1, 0},
                           {0, 0, 0, 0},
                           {1, 1, 1, 1},
                           {0, 0, 0, 0}} ;

    int array13[4][4] = {    {0, 1, 1, 0},
                             {0, 0, 0, 0},
                             {0, 0, 0, 0},
                             {0, 1, 1, 0}} ;

    int array14[4][4] = {    {1, 0, 1, 1},
                             {0, 1, 0, 1},
                             {1, 0, 1, 0},
                             {1, 1, 0, 1}} ;

    int array15[4][4] = {   {0, 1, 0, 1},
                            {1, 0, 0, 0},
                            {1, 0, 0, 0},
                            {0, 1, 0, 1}} ;

    int array16[4][4] = {   {0, 1, 1, 0},
                            {1, 1, 1, 1},
                            {1, 1, 1, 1},
                            {0, 1, 1, 0}} ;

    int array17[4][4] = {  {0, 1, 1, 1},
                           {0, 1, 0, 0},
                           {0, 0, 1, 0},
                           {1, 1, 1, 0}} ;

    int array18[4][4] = { {0, 0, 0, 1},
                          {0, 0, 1, 0},
                          {0, 1, 0, 0},
                          {1, 0, 0, 0}} ;

    int array19[4][4] = {   {0, 1, 0, 0},
                            {0, 1, 1, 0},
                            {0, 0, 1, 1},
                            {0, 0, 0, 0}} ;

    int array20[4][4] = {  {0, 0, 0, 0},
                           {0, 0, 0, 0},
                           {0, 0, 0, 0},
                           {0, 0, 0, 0}} ;

    int count=0;
    mData.insert(count++,pushData(array1));
    mData.insert(count++,pushData(array2));
    mData.insert(count++,pushData(array3));
    mData.insert(count++,pushData(array4));
    mData.insert(count++,pushData(array5));
    mData.insert(count++,pushData(array6));
    mData.insert(count++,pushData(array7));
    mData.insert(count++,pushData(array8));
    mData.insert(count++,pushData(array9));
    mData.insert(count++,pushData(array10));
    mData.insert(count++,pushData(array11));
    mData.insert(count++,pushData(array12));
    mData.insert(count++,pushData(array13));
    mData.insert(count++,pushData(array14));
    mData.insert(count++,pushData(array15));
    mData.insert(count++,pushData(array16));
    mData.insert(count++,pushData(array17));
    mData.insert(count++,pushData(array18));
    mData.insert(count++,pushData(array19));
    mData.insert(count++,pushData(array20));


    //测试数据
//    for( QMap<int, QVector< QVector<int> > >::iterator it = mData.begin();it != mData.end();it++ )
//    {
//        for(QVector< QVector<int> >::iterator it2 = (*it).begin(); it2!= (*it).end();it2++)
//        {
//            for(QVector<int>::iterator it3 = (*it2).begin(); it3 != (*it2).end(); it3++ )
//            {
//                qDebug() << *it3 ;
//            }
//        }
//        qDebug() << endl;
//    }

}

QVector< QVector<int>> DataConfig:: pushData(int array[4][4])
{
    QVector< QVector<int>> v;
    for(int i = 0 ; i < 4;i++)
    {
        QVector<int>v1;
        for(int j = 0 ; j < 4;j++)
        {
            v1.push_back(array[i][j]);
        }
        v.push_back(v1);
    }

    return v;
}
