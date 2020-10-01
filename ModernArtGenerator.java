                                                                         

public class ModernArtGenerator extends Application {
    @Override
    public void start(Stage primaryStage) {
        Pane pane = new Pane();
        pane.setPrefWidth(600);
        pane.setPrefHeight(300);
        int x, y, width, height;
        Random random = new Random();
        for(int i = 0; i < 50 ; i++) {
            Rectangle rectangle = new Rectangle();
            rectangle.setFill(Color.color(random.nextFloat(), random.nextFloat(), random.nextFloat(),random.nextFloat()));
            width = random.nextInt(91)+10;
            height = random.nextInt(91)+10;
            x = random.nextInt(600-width);
            y = random.nextInt(300-height);
            rectangle.setX(x);
            rectangle.setY(y);
            rectangle.setWidth(width);
            rectangle.setHeight(height);
            pane.getChildren().add(rectangle);
        }
        Scene scene = new Scene(pane);
        primaryStage.setTitle("Modern Art Generator");
        primaryStage.setScene(scene);
        primaryStage.show();
    }
}