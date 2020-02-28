ARGV.each do |key|
    if key.ends_with?(".kai")
        puts "#{key}"
    else 
        puts "wrong file type"
    end
end
