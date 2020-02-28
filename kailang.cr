ARGV.each do |key|
    if key.ends_with?(".kai")
        filename = "#{key}"
        main filename
    else 
        puts "wrong file type"
    end
end

def main (filename)
    file = File.read filename
    puts file
end
