# [Bronze I] 双六 (Sugoroku) - 15475 

[문제 링크](https://www.acmicpc.net/problem/15475) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

구현

### 제출 일자

2025년 5월 20일 16:57:59

### 문제 설명

<p>JOI 君はおじさんの家で双六を見つけた．双六は直線状に並んだ <var>N+2</var> 個のマスからなり，<var>1</var> 番目のマスはスタート，<var>N+2</var> 番目のマスはゴールである．その他の各マスには <var>0</var> または <var>1</var> が書かれていて，各 <var>i</var> (<var>1≦i≦N</var>) について，<var>i+1</var> 番目のマスに書かれた数字は <var>A_i</var> である．</p>

<p>双六では，最初にスタートのマスにコマを置き，サイコロを振って，出た目の数だけコマを進めることを繰り返す．ただし，<var>1</var> の書かれたマスに止まった場合は，ゲームオーバーである．ゲームオーバーにならずにゴールのマスに止まるか，ゴールのマスを通り過ぎたら，ゲームクリアである．</p>

<p>JOI 君は双六を遊ぶためのサイコロをおもちゃ屋さんに買いに行くことにした．おもちゃ屋さんには <var>N+1</var> 個のサイコロが売っている．<var>j</var> 番目 (<var>1≦j≦N+1</var>) のサイコロは <var>j</var> 個の面を持ち，<var>1,2,...,j</var> が <var>1</var> つずつ書かれている．</p>

<p>JOI 君はゲームクリアできるようなサイコロのうち，最も面の数が少ないサイコロを <var>1</var> 個買うことにした．JOI 君はどのサイコロを買えばよいだろうか．</p>

### 입력 

 <p>入力は以下の形式で標準入力から与えられる．</p>

<pre><var>N</var>
<var>A_1</var> <var>A_2</var> ... <var>A_N</var>
</pre>

### 출력 

 <p>JOI 君が購入すべきサイコロの面の数を答えよ．</p>

