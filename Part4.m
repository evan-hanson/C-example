clear
clc
close All


fileIDCount = fopen('counts.txt','r');
count = fscanf(fileIDCount,'%d');
fclose(fileIDCount);

text = string(fileread('words.txt'));
%word = fscanf(fileIDWord,'%s',Inf);

words = split(text);

figure
wordcloud(words,count);
title("The Hunger Games")

size = length(words);


topCount = zeros(1,10);

for(i=0:9)
    topWords(i+1) = words(size - i);
    topCount(i+1) = count(size - i);
end

figure
bar(topCount,'b');
title("Top 10 common words in The Hunger Games")
set(gca,'xticklabel',{topWords(1),topWords(2),topWords(3),topWords(4),topWords(5),topWords(6),topWords(7),topWords(8),topWords(9),topWords(10)});