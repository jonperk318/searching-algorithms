import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws FileNotFoundException {

        // get sizes of sample arrays
        final ArrayList<Integer> sampleSizes = getSampleSizes();

        // build array of arrays with samples
        final ArrayList<ArrayList<Integer>> samples = getSamples(sampleSizes);

        // get list of random ints
        final ArrayList<Integer> randomInts = getRandomInts();

        // build sorted array
        ArrayList<ArrayList<Integer>> sortedSamples = new ArrayList<>();
        for (ArrayList<Integer> sample : samples) {
            ArrayList<Integer> sortedSample = new ArrayList<>(sample);
            Collections.sort(sortedSample);
            sortedSamples.add(sortedSample);
        }

        Utils.printArray(samples.getFirst());

        ArrayList<Double> linearTimes1 = new ArrayList<>(), linearTimes2 = new ArrayList<>(),
                linearTimes3 = new ArrayList<>(), binaryTimes1 = new ArrayList<>(), binaryTimes2 = new ArrayList<>(),
                binaryTimes3 = new ArrayList<>(), ternaryTimes1 = new ArrayList<>(), ternaryTimes2 = new ArrayList<>(),
                ternaryTimes3 = new ArrayList<>();

        double tick, tock;

        for (int i = 0; i < samples.size(); i++) { // RUN ALL SEARCHING FUNCTIONS

            int randomInt = randomInts.get(i); // test all three algorithms on same arr and same key
            int notPresentInt = 1_000_001;

            // Linear search with random key
            tick = System.nanoTime();
            LinearSearch.search(samples.get(i), randomInt);
            tock = System.nanoTime();
            linearTimes1.add((tock - tick) / 1_000_000_000);

            // Linear search with key equal to first element in array
            tick = System.nanoTime();
            LinearSearch.search(samples.get(i), samples.get(i).getFirst());
            tock = System.nanoTime();
            linearTimes2.add((tock - tick) / 1_000_000_000);

            // Linear search with key not present in array
            tick = System.nanoTime();
            LinearSearch.search(samples.get(i), notPresentInt);
            tock = System.nanoTime();
            linearTimes3.add((tock - tick) / 1_000_000_000);

            // Binary search with random key
            tick = System.nanoTime();
            BinarySearch.search(sortedSamples.get(i), randomInt);
            tock = System.nanoTime();
            binaryTimes1.add((tock - tick) / 1_000_000_000);

            // Binary search with key equal to first element in array
            tick = System.nanoTime();
            BinarySearch.search(sortedSamples.get(i), sortedSamples.get(i).getFirst());
            tock = System.nanoTime();
            binaryTimes2.add((tock - tick) / 1_000_000_000);

            // Binary search with key not present in array
            tick = System.nanoTime();
            BinarySearch.search(sortedSamples.get(i), notPresentInt);
            tock = System.nanoTime();
            binaryTimes3.add((tock - tick) / 1_000_000_000);

            // Ternary search with random key
            tick = System.nanoTime();
            TernarySearch.search(sortedSamples.get(i), randomInt);
            tock = System.nanoTime();
            ternaryTimes1.add((tock - tick) / 1_000_000_000);

            // Ternary search with key equal to first element in array
            tick = System.nanoTime();
            TernarySearch.search(sortedSamples.get(i), sortedSamples.get(i).getFirst());
            tock = System.nanoTime();
            ternaryTimes2.add((tock - tick) / 1_000_000_000);

            // Ternary search with key not present in array
            tick = System.nanoTime();
            TernarySearch.search(sortedSamples.get(i), notPresentInt);
            tock = System.nanoTime();
            ternaryTimes3.add((tock - tick) / 1_000_000_000);

            System.out.println("Searched array of length: " + sampleSizes.get(i));
        }

        // write sorting times to separate files
        ArrayList<ArrayList<Double>> searchingTimes = new ArrayList<>();
        searchingTimes.add(linearTimes1);
        searchingTimes.add(linearTimes2);
        searchingTimes.add(linearTimes3);
        searchingTimes.add(binaryTimes1);
        searchingTimes.add(binaryTimes2);
        searchingTimes.add(binaryTimes3);
        searchingTimes.add(ternaryTimes1);
        searchingTimes.add(ternaryTimes2);
        searchingTimes.add(ternaryTimes3);
        String[] searchingNames = {"linear-times-1", "linear-times-2", "linear-times-3", "binary-times-1",
                "binary-times-2", "binary-times-3", "ternary-times-1", "ternary-times-2", "ternary-times-3"};

        for (int i = 0; i < searchingTimes.size(); i++) {

            try (PrintWriter out = new PrintWriter("java-searching-times/java-" +
                    searchingNames[i] + ".txt")) {

                for (Double time : searchingTimes.get(i)) {
                    out.write(time + ",");
                }

            }

        }

    }

    private static ArrayList<Integer> getRandomInts() {

        final ArrayList<Integer> randomInts = new ArrayList<>();
        File randomIntsFile = new File("../samples/random-ints.txt");

        try (Scanner riIn = new Scanner(randomIntsFile)) {
            String line = riIn.nextLine();
            String[] randomIntStrings = line.split(",");

            for (String randomIntString : randomIntStrings) {
                int value = Integer.parseInt(randomIntString);
                randomInts.add(value);
            }

        } catch (FileNotFoundException e) {
            throw new RuntimeException(e);
        }
        return randomInts;
    }

    private static ArrayList<ArrayList<Integer>> getSamples(ArrayList<Integer> sampleSizes) {

        ArrayList<ArrayList<Integer>> samples = new ArrayList<>();

        for (Integer sampleSize : sampleSizes) {

            File f = new File("../samples/" + sampleSize + ".txt");

            try (Scanner in = new Scanner(f)) {

                String line = in.nextLine();
                String[] sampleString = line.split(",");
                ArrayList<Integer> temp = new ArrayList<>();

                for (String sample : sampleString) {
                    int value = Integer.parseInt(sample);
                    temp.add(value);
                }

                samples.add(temp);

            } catch (FileNotFoundException e) {
                throw new RuntimeException(e);
            }
        }
        return samples;
    }

    private static ArrayList<Integer> getSampleSizes() {
        File sampleSizesFile = new File("../samples/sample-sizes.txt");
        ArrayList<Integer> sampleSizes = new ArrayList<>();

        // read sample sizes file to an array
        try (Scanner ssIn = new Scanner(sampleSizesFile)) {
            String line = ssIn.nextLine();
            String[] sampleSizesString = line.split(",");

            for (String sample : sampleSizesString) {
                int value = Integer.parseInt(sample);
                sampleSizes.add(value);
            }

        } catch (FileNotFoundException e) {
            throw new RuntimeException(e);
        }
        return sampleSizes;
    }

}