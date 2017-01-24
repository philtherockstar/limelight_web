#!/bin/bash


files="
bootstrap			
jquery.isotope.center	
jquery.unveilEffects
custom-portfolio-masonry	
jquery.jigowatt		
custom			
jquery.mb.YTPlayer		
jquery.animateNumber		
jquery.parallax-1.1.3	
scrollReveal
smooth-scroll
jquery.event.move		
jquery.twentytwenty		
"

for file in $files
do
  wget --post-data="input=`cat $file.js`" --output-document=$file.min.js https://javascript-minifier.com/raw
done
